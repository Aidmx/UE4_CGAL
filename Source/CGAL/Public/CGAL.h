
#pragma once

#include "Modules/ModuleManager.h"



class FCGALModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/** Handle to the test dll we will load */
	void *GetLIBGMP_LibraryHandle() { return LIBGMP_LibraryHandle; }
	void *GetLIBMPFR_LibraryHandle() { return LIBMPFR_LibraryHandle; }

private:
	/** Handle to the test dll we will load */
	void *LIBGMP_LibraryHandle;
	void *LIBMPFR_LibraryHandle;
};
