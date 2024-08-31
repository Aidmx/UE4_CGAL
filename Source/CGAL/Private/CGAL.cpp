#include "CGAL.h"
//#include "CGALPrivatePCH.h"
#include "Core.h"
#include "Modules/ModuleManager.h"


#define LOCTEXT_NAMESPACE "FCGALModule"

void FCGALModule::StartupModule()
{

	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FString BaseDir = "YOUR UE4 PROJECT PATH/Plugins/CGAL";

	// Add on the relative location of the third party dll and load it
	FString LIBGMP,LIBMPFR;
#if PLATFORM_WINDOWS
	LIBGMP = FPaths::Combine(*BaseDir, TEXT("Binaries:Win64/libgmp-10.dll"));
	LIBMPFR = FPaths::Combine(*BaseDir, TEXT("Binaries:Win64/libmpfr-4.dll"));
#endif // PLATFORM_WINDOWS

	LIBGMP_LibraryHandle = !LIBGMP.IsEmpty() ? FPlatformProcess::GetDllHandle(*LIBGMP) : nullptr;
	LIBMPFR_LibraryHandle = !LIBMPFR.IsEmpty() ? FPlatformProcess::GetDllHandle(*LIBMPFR) : nullptr;
}

void FCGALModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	FPlatformProcess::FreeDllHandle(LIBGMP_LibraryHandle);
	LIBGMP_LibraryHandle = nullptr;
	FPlatformProcess::FreeDllHandle(LIBMPFR_LibraryHandle);
	LIBMPFR_LibraryHandle = nullptr;
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FCGALModule, CGAL)
