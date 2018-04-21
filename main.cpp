#include "header.hpp"

#define UMBRALMAX 83



int main(int argc, char* argv[])
{


	ModGod();


		#if defined (LINUX)
		    void *hDLL;		// Handle to .so library
		#else
		    HINSTANCE hDLL;		// Handle to DLL
		#endif

		LPAdapterInfo lpAdapterInfo = NULL;
	    int ADL_Err = ADL_ERR;
	    int iNumberAdapters = 0;
		int iOverdriveSupported = 0;
		int iOverdriveEnabled = 0;		
		int iOverdriveVersion = 0;
	
		#if defined (LINUX)

		    hDLL = dlopen( "libatiadlxx.so", RTLD_LAZY|RTLD_GLOBAL);

		#else

		    hDLL = LoadLibrary("atiadlxx.dll");

	        // A 32 bit calling application on 64 bit OS will fail to LoadLIbrary.
	        // Try to load the 32 bit library (atiadlxy.dll) instead		    
		    if (hDLL == NULL)
		        hDLL = LoadLibrary("atiadlxy.dll");

		#endif

        if (NULL == hDLL)
        {
            puts("[!] ADL library not found");
            return -1;
        }

		ADL_Main_Control_Create = (ADL_MAIN_CONTROL_CREATE) GetProcAddress(hDLL,"ADL_Main_Control_Create");

        ADL_Main_Control_Destroy = (ADL_MAIN_CONTROL_DESTROY) GetProcAddress(hDLL,"ADL_Main_Control_Destroy");

        ADL_Adapter_NumberOfAdapters_Get = (ADL_ADAPTER_NUMBEROFADAPTERS_GET) GetProcAddress(hDLL,"ADL_Adapter_NumberOfAdapters_Get");

        ADL_Adapter_AdapterInfo_Get = (ADL_ADAPTER_ADAPTERINFO_GET) GetProcAddress(hDLL,"ADL_Adapter_AdapterInfo_Get");

		ADL_Overdrive_Caps = (ADL_OVERDRIVE_CAPS)GetProcAddress(hDLL, "ADL_Overdrive_Caps");




		if (NULL == ADL_Main_Control_Create || NULL == ADL_Main_Control_Destroy || NULL == ADL_Adapter_NumberOfAdapters_Get || NULL == ADL_Adapter_AdapterInfo_Get || NULL == ADL_Overdrive_Caps)
		{
	       puts("[!] AMD ADL API is missing!");
		   return -2; 
		}


		// Initialize ADL. The second parameter is 1, which means:
        // retrieve adapter information only for adapters that are physically present and enabled in the system
        if ( ADL_OK != ADL_Main_Control_Create (ADL_Main_Memory_Alloc, 1) )
		{
	       puts("[!] ADL Initialization Error!");
		   return -5;
		}



        // Obtain the number of adapters for the system
        if ( ADL_OK != ADL_Adapter_NumberOfAdapters_Get ( &iNumberAdapters ) )
		{
	       puts("[!] Cannot get the number of adapters!");
		   return -4;
		}



        if ( 0 < iNumberAdapters )
        {
            lpAdapterInfo = (LPAdapterInfo)malloc ( sizeof (AdapterInfo) * iNumberAdapters );
            memset (lpAdapterInfo,'\0', sizeof (AdapterInfo) * iNumberAdapters);

            // Get the AdapterInfo structure for all adapters in the system
            ADL_Adapter_AdapterInfo_Get (lpAdapterInfo, sizeof (AdapterInfo) * iNumberAdapters);
        }


		int ignoreDevs[iNumberAdapters];
		int countIgnore = 0;

		ignoreDevs[countIgnore] = 0;
		countIgnore++;

		printf("[+] Number adapter(s) found  %d\n", iNumberAdapters);

        
		int adapterId = 1;		


		//Overdrive 5 APIs should be used if returned version indicates 5. Overdrive 6 APIs are used if 6 is returned.
		//Overdrive 5 is supported on legacy ASICs. Newer ASICs (CIK+) should report Overdrive 6
		if ( ADL_OK != ADL_Overdrive_Caps (adapterId, &iOverdriveSupported, &iOverdriveEnabled, &iOverdriveVersion) )
		{
		   printf("[!] Can’t get Overdrive capabilities \n");
		   return -80;
		}




		if (!iOverdriveSupported)
		{
		   printf("[!] Overdrive is not supported \n");
		   return -50;
		}


		printf("[+] Overdrive number version %d installed\n", iOverdriveVersion);

		//GetInfoDevice(adapterId, hDLL);
		//exit(0);


		/*
		if (iOverdriveVersion == 6)
		{	


		bool omitir;

		
		for (int register i = 0; i < iNumberAdapters; i++ )
        {

				GetInfoTemperatureOd6(i, hDLL);
				printf("\n\n[+] Checking devices number %d", i);
				printf("\nTemp %dC\n", tempCelsius);

				if(tempCelsius>=UMBRALMAX)
				{
					puts("[!] This GPU overheat umbral temperature bypassed.. calling shutters");
					apagarFuego();
				}

				omitir= false;

				for(int register a=0; a<=countIgnore; a++)
				{
					if(ignoreDevs[a]==i)
					{
						printf("\n\n[+] Ignore FANSPEED device number %d\n\n", a);
						omitir = true;
						break;
					}					
				}

				if(omitir)
					continue;

	        	GetInfoFanOd6(i, hDLL);
	        	printf("FAN Max %d RPM\n", fanRpmMax);
	        	printf("FAN Min %d RPM\n", fanRpmMin);
	        	printf("FAN Current %d RPM\n", fanRpmCurr);


	        	if(fanRpmMax<=0 || fanRpmMin<=0 || fanRpmCurr<=0)
	        	{
					puts("[!] Unable comunication to FAN this GPU.. calling shutters");
					apagarFuego();
	        	}

	        	sleep(1);

	        if((i+1)==iNumberAdapters)
	        	i=-1;

		}

		}*/		

		
		if (iOverdriveVersion == 6)
		{	


		bool omitir;
		
		for (int register i = 0; i < iNumberAdapters; i++ )
        {

				GetInfoTemperatureOd5(i, hDLL);
				printf("\n\n[+] Checking devices number %d", i);
				printf("\nTemp %dC\n", tempCelsius);

				if(tempCelsius>=UMBRALMAX)
				{
					puts("[!] This GPU overheat umbral temperature bypassed.. calling shutters");
					apagarFuego();
				}

				omitir= false;

				for(int register a=0; a<=countIgnore; a++)
				{
					if(ignoreDevs[a]==i)
					{
						printf("\n\n[+] Ignore FANSPEED device number %d\n\n", a);
						omitir = true;
						break;
					}					
				}

				if(omitir)
					continue;

	        	GetInfoFanOd5(i, hDLL);
	        	printf("FAN Max %d RPM\n", fanRpmMax);
	        	printf("FAN Min %d RPM\n", fanRpmMin);
	        	printf("FAN Current %d RPM\n", fanRpmCurr);


	        	if(fanRpmMax<=0 || fanRpmMin<=0 || fanRpmCurr<=0)
	        	{
					puts("[!] Unable comunication to FAN this GPU.. calling shutters");
					apagarFuego();
	        	}

	        	sleep(1);

	        if((i+1)==iNumberAdapters)
	        	i=-1;

		}

		}		
}
