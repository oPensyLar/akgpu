#define LINUX

#if defined (LINUX)

	#include <ADL/adl_sdk.h>
	#include <ADL/adl_structures.h>
	#include <dlfcn.h>
	#include <stdlib.h>
	#include <string.h>
	#include <unistd.h>
	#include <linux/reboot.h>
	#include <sys/reboot.h>

#else

	#include <windows.h>
	#include <tchar.h>
	#include "ADL/adl_structures.h"

#endif

#include <stdio.h>


#define AMDVENDORID             (1002)
#define ADL_WARNING_NO_DATA      -100


// Definitions of the used function pointers. Add more if you use other ADL APIs
typedef int ( *ADL_MAIN_CONTROL_CREATE )(ADL_MAIN_MALLOC_CALLBACK, int );
typedef int ( *ADL_MAIN_CONTROL_DESTROY )();
typedef int ( *ADL_ADAPTER_NUMBEROFADAPTERS_GET ) ( int* );
typedef int ( *ADL_ADAPTER_ADAPTERINFO_GET ) ( LPAdapterInfo, int );
typedef int ( *ADL_ADAPTER_ACTIVE_GET ) ( int, int* );
typedef int ( *ADL_OVERDRIVE_CAPS ) (int iAdapterIndex, int *iSupported, int *iEnabled, int *iVersion);




typedef int ( *ADL_OVERDRIVE5_THERMALDEVICES_ENUM ) (int iAdapterIndex, int iThermalControllerIndex, ADLThermalControllerInfo *lpThermalControllerInfo);

typedef int ( *ADL_OVERDRIVE5_ODPARAMETERS_GET ) ( int  iAdapterIndex,  ADLODParameters *  lpOdParameters );
typedef int ( *ADL_OVERDRIVE5_TEMPERATURE_GET ) (int iAdapterIndex, int iThermalControllerIndex, ADLTemperature *lpTemperature);
typedef int ( *ADL_OVERDRIVE5_FANSPEED_GET ) (int iAdapterIndex, int iThermalControllerIndex, ADLFanSpeedValue *lpFanSpeedValue);
typedef int ( *ADL_OVERDRIVE5_FANSPEEDINFO_GET ) (int iAdapterIndex, int iThermalControllerIndex, ADLFanSpeedInfo *lpFanSpeedInfo);
typedef int ( *ADL_OVERDRIVE5_ODPERFORMANCELEVELS_GET ) (int iAdapterIndex, int iDefault, ADLODPerformanceLevels *lpOdPerformanceLevels); 
typedef int ( *ADL_OVERDRIVE5_ODPARAMETERS_GET ) (int iAdapterIndex, ADLODParameters *lpOdParameters);
typedef int ( *ADL_OVERDRIVE5_CURRENTACTIVITY_GET ) (int iAdapterIndex, ADLPMActivity *lpActivity);
typedef int	( *ADL_OVERDRIVE5_FANSPEED_SET )(int iAdapterIndex, int iThermalControllerIndex, ADLFanSpeedValue *lpFanSpeedValue);
typedef int ( *ADL_OVERDRIVE5_ODPERFORMANCELEVELS_SET ) (int iAdapterIndex, ADLODPerformanceLevels *lpOdPerformanceLevels);
typedef int ( *ADL_OVERDRIVE5_POWERCONTROL_CAPS )(int iAdapterIndex,  int *lpSupported);
typedef int ( *ADL_OVERDRIVE5_POWERCONTROLINFO_GET )(int iAdapterIndex, ADLPowerControlInfo *lpPowerControlInfo);
typedef int ( *ADL_OVERDRIVE5_POWERCONTROL_GET )(int iAdapterIndex, int *lpCurrentValue, int *lpDefaultValue);
typedef int ( *ADL_OVERDRIVE5_POWERCONTROL_SET )(int iAdapterIndex, int iValue);
typedef int ( *ADL_DISPLAY_DDCINFO_GET)(int iAdapterIndex, int iDisplayIndex, ADLDDCInfo * lpInfo);






typedef int ( *ADL_OVERDRIVE6_THERMALDEVICES_ENUM ) (int iAdapterIndex, int iThermalControllerIndex, ADLThermalControllerInfo *lpThermalControllerInfo);

typedef int ( *ADL_OVERDRIVE6_ODPARAMETERS_GET ) ( int  iAdapterIndex,  ADLODParameters *  lpOdParameters );
typedef int ( *ADL_OVERDRIVE6_TEMPERATURE_GET ) (int iAdapterIndex, int iThermalControllerIndex, ADLTemperature *lpTemperature);
typedef int ( *ADL_OVERDRIVE6_FANSPEED_GET ) (int iAdapterIndex, int iThermalControllerIndex, ADLFanSpeedValue *lpFanSpeedValue);
typedef int ( *ADL_OVERDRIVE6_FANSPEEDINFO_GET ) (int iAdapterIndex, int iThermalControllerIndex, ADLFanSpeedInfo *lpFanSpeedInfo);
typedef int ( *ADL_OVERDRIVE6_ODPERFORMANCELEVELS_GET ) (int iAdapterIndex, int iDefault, ADLODPerformanceLevels *lpOdPerformanceLevels); 
typedef int ( *ADL_OVERDRIVE6_ODPARAMETERS_GET ) (int iAdapterIndex, ADLODParameters *lpOdParameters);
typedef int ( *ADL_OVERDRIVE6_CURRENTACTIVITY_GET ) (int iAdapterIndex, ADLPMActivity *lpActivity);
typedef int	( *ADL_OVERDRIVE6_FANSPEED_SET )(int iAdapterIndex, int iThermalControllerIndex, ADLFanSpeedValue *lpFanSpeedValue);
typedef int ( *ADL_OVERDRIVE6_ODPERFORMANCELEVELS_SET ) (int iAdapterIndex, ADLODPerformanceLevels *lpOdPerformanceLevels);
typedef int ( *ADL_OVERDRIVE6_POWERCONTROL_CAPS )(int iAdapterIndex,  int *lpSupported);
typedef int ( *ADL_OVERDRIVE6_POWERCONTROLINFO_GET )(int iAdapterIndex, ADLPowerControlInfo *lpPowerControlInfo);
typedef int ( *ADL_OVERDRIVE6_POWERCONTROL_GET )(int iAdapterIndex, int *lpCurrentValue, int *lpDefaultValue);
typedef int ( *ADL_OVERDRIVE6_POWERCONTROL_SET )(int iAdapterIndex, int iValue);
typedef int ( *ADL_DISPLAY_DDCINFO_GET)(int iAdapterIndex, int iDisplayIndex, ADLDDCInfo * lpInfo);






typedef int ( *ADL_OVERDRIVE6_THERMALCONTROLLER_CAPS )(int iAdapterIndex, ADLOD6ThermalControllerCaps *lpThermalControllerCaps);




typedef int ( *ADL_OVERDRIVE6_CAPABILITIES_GET ) (int iAdapterIndex, ADLOD6Capabilities *lpODCapabilities);
typedef int ( *ADL_OVERDRIVE6_STATEINFO_GET )(int iAdapterIndex, int iStateType, ADLOD6StateInfo *lpStateInfo);
typedef int	( *ADL_OVERDRIVE6_CURRENTSTATUS_GET )(int iAdapterIndex, ADLOD6CurrentStatus *lpCurrentStatus);
typedef int ( *ADL_OVERDRIVE6_POWERCONTROL_CAPS ) (int iAdapterIndex, int *lpSupported);


typedef int ( *ADL_OVERDRIVE6_POWERCONTROL_GET )(int iAdapterIndex, int *lpCurrentValue, int *lpDefaultValue);

typedef int ( *ADL_OVERDRIVE6_STATE_SET )(int iAdapterIndex, int iStateType, ADLOD6StateInfo *lpStateInfo);
typedef int ( *ADL_OVERDRIVE6_POWERCONTROL_SET )(int iAdapterIndex, int iValue);







// Memory allocation function
void* __stdcall ADL_Main_Memory_Alloc ( int iSize )
{
    void* lpBuffer = malloc ( iSize );
    return lpBuffer;
}





// Optional Memory de-allocation function
void __stdcall ADL_Main_Memory_Free ( void** lpBuffer )
{
    if ( NULL != *lpBuffer )
    {
        free ( *lpBuffer );
        *lpBuffer = NULL;
    }
}





#if defined (LINUX)
// equivalent functions in linux
void * GetProcAddress( void * pLibrary, const char * name)
{
    return dlsym( pLibrary, name);
}
#endif



ADL_MAIN_CONTROL_CREATE					ADL_Main_Control_Create;
ADL_MAIN_CONTROL_DESTROY				ADL_Main_Control_Destroy;
ADL_ADAPTER_NUMBEROFADAPTERS_GET		ADL_Adapter_NumberOfAdapters_Get;
ADL_ADAPTER_ADAPTERINFO_GET				ADL_Adapter_AdapterInfo_Get;
ADL_OVERDRIVE_CAPS						ADL_Overdrive_Caps;
ADL_DISPLAY_DDCINFO_GET 				ADL_Display_DDCInfo_Get;



ADL_OVERDRIVE5_THERMALDEVICES_ENUM		ADL_Overdrive5_ThermalDevices_Enum;
ADL_OVERDRIVE5_ODPARAMETERS_GET			ADL_Overdrive5_ODParameters_Get;
ADL_OVERDRIVE5_TEMPERATURE_GET			ADL_Overdrive5_Temperature_Get;
ADL_OVERDRIVE5_FANSPEED_GET				ADL_Overdrive5_FanSpeed_Get;
ADL_OVERDRIVE5_FANSPEEDINFO_GET			ADL_Overdrive5_FanSpeedInfo_Get;
ADL_OVERDRIVE5_ODPERFORMANCELEVELS_GET	ADL_Overdrive5_ODPerformanceLevels_Get;
ADL_OVERDRIVE5_CURRENTACTIVITY_GET		ADL_Overdrive5_CurrentActivity_Get;
ADL_OVERDRIVE5_FANSPEED_SET				ADL_Overdrive5_FanSpeed_Set;
ADL_OVERDRIVE5_ODPERFORMANCELEVELS_SET  ADL_Overdrive5_ODPerformanceLevels_Set;
ADL_OVERDRIVE5_POWERCONTROL_CAPS		ADL_Overdrive5_PowerControl_Caps;
ADL_OVERDRIVE5_POWERCONTROLINFO_GET		ADL_Overdrive5_PowerControlInfo_Get;
ADL_OVERDRIVE5_POWERCONTROL_GET			ADL_Overdrive5_PowerControl_Get;
ADL_OVERDRIVE5_POWERCONTROL_SET			ADL_Overdrive5_PowerControl_Set;


ADL_OVERDRIVE6_THERMALDEVICES_ENUM		ADL_Overdrive6_ThermalDevices_Enum;
ADL_OVERDRIVE6_ODPARAMETERS_GET			ADL_Overdrive6_ODParameters_Get;
ADL_OVERDRIVE6_TEMPERATURE_GET			ADL_Overdrive6_Temperature_Get;
ADL_OVERDRIVE6_FANSPEED_GET				ADL_Overdrive6_FanSpeed_Get;
ADL_OVERDRIVE6_FANSPEEDINFO_GET			ADL_Overdrive6_FanSpeedInfo_Get;
ADL_OVERDRIVE6_ODPERFORMANCELEVELS_GET	ADL_Overdrive6_ODPerformanceLevels_Get;
ADL_OVERDRIVE6_CURRENTACTIVITY_GET		ADL_Overdrive6_CurrentActivity_Get;
ADL_OVERDRIVE6_FANSPEED_SET				ADL_Overdrive6_FanSpeed_Set;
ADL_OVERDRIVE6_ODPERFORMANCELEVELS_SET  ADL_Overdrive6_ODPerformanceLevels_Set;
ADL_OVERDRIVE6_POWERCONTROL_CAPS		ADL_Overdrive6_PowerControl_Caps;
ADL_OVERDRIVE6_POWERCONTROLINFO_GET		ADL_Overdrive6_PowerControlInfo_Get;
ADL_OVERDRIVE6_POWERCONTROL_GET			ADL_Overdrive6_PowerControl_Get;
ADL_OVERDRIVE6_POWERCONTROL_SET			ADL_Overdrive6_PowerControl_Set;


int GetInfoDevice(int adapterId, void* hDLL)
{


	ADL_Display_DDCInfo_Get = (ADL_DISPLAY_DDCINFO_GET) GetProcAddress (hDLL, "ADL_Display_DDCInfo_Get");

	ADLDDCInfo lpInfo;

	if(ADL_OK == ADL_Display_DDCInfo_Get(adapterId, 1, &lpInfo))
	{
		printf("PEPAAA %s\n", lpInfo.cDisplayName);

	}

	exit(0);

	return 0;
}





int ModGod()
{

	int ret = 0;

	if(setuid(0))
	{
		perror("setuid");
		ret = -1;
	}


	return ret;
}




int apagarFuego()
{

	sync();

	return reboot(LINUX_REBOOT_CMD_RESTART);
}




int tempCelsius;

int GetInfoTemperatureOd5(int adapterId, void* hDLL)
{

	ADL_Overdrive5_ThermalDevices_Enum = (ADL_OVERDRIVE5_THERMALDEVICES_ENUM) GetProcAddress (hDLL, "ADL_Overdrive5_ThermalDevices_Enum");

	ADL_Overdrive5_Temperature_Get = (ADL_OVERDRIVE5_TEMPERATURE_GET) GetProcAddress (hDLL, "ADL_Overdrive5_Temperature_Get");


	if (NULL == ADL_Overdrive5_ThermalDevices_Enum || NULL == ADL_Overdrive5_Temperature_Get)
	{
       puts("ADL's API is missing!\n");
	   return -10; 
	}

	
	int  ADL_Err = ADL_ERR;
	int maxThermalControllerIndex = 0;


	ADLThermalControllerInfo termalControllerInfo = {0};
	termalControllerInfo.iSize = sizeof (ADLThermalControllerInfo);



	for (int iThermalControllerIndex = 0; iThermalControllerIndex < 10; iThermalControllerIndex++) 
	{
		ADL_Err = ADL_Overdrive5_ThermalDevices_Enum (adapterId, iThermalControllerIndex, &termalControllerInfo);

		if (ADL_Err == ADL_WARNING_NO_DATA)
		{
			maxThermalControllerIndex = iThermalControllerIndex - 1;
			break;
		}

		if (ADL_Err == ADL_WARNING_NO_DATA)
		{
		   puts("[!] Failed to enumerate thermal devices");
		   return -50;
		}			

		if (termalControllerInfo.iThermalDomain == ADL_DL_THERMAL_DOMAIN_GPU)
		{

			ADLTemperature adlTemperature = {0};
			adlTemperature.iSize = sizeof (ADLTemperature);

			if (ADL_OK != ADL_Overdrive5_Temperature_Get ( adapterId, iThermalControllerIndex, &adlTemperature ))
			{
				puts("[!] Failed to get thermal devices temperature");
				return 0;
			}


			// The temperature is returned in millidegrees Celsius.
			tempCelsius = adlTemperature.iTemperature / 1000;
			//printf ("[+] Current temperature: %d\n", tempCelsius);


		}	

	}


	return 0;
}




int GetInfoTemperatureOd6(int adapterId, void* hDLL)
{

	ADL_Overdrive6_ThermalDevices_Enum = (ADL_OVERDRIVE6_THERMALDEVICES_ENUM) GetProcAddress (hDLL, "ADL_Overdrive6_ThermalDevices_Enum");

	ADL_Overdrive6_Temperature_Get = (ADL_OVERDRIVE6_TEMPERATURE_GET) GetProcAddress (hDLL, "ADL_Overdrive6_Temperature_Get");


	if (NULL == ADL_Overdrive6_ThermalDevices_Enum || NULL == ADL_Overdrive6_Temperature_Get)
	{
       puts("ADL's API is missing!\n");
	   return -10; 
	}

	
	int  ADL_Err = ADL_ERR;
	int maxThermalControllerIndex = 0;


	ADLThermalControllerInfo termalControllerInfo = {0};
	termalControllerInfo.iSize = sizeof (ADLThermalControllerInfo);



	for (int iThermalControllerIndex = 0; iThermalControllerIndex < 10; iThermalControllerIndex++) 
	{
		ADL_Err = ADL_Overdrive6_ThermalDevices_Enum (adapterId, iThermalControllerIndex, &termalControllerInfo);

		if (ADL_Err == ADL_WARNING_NO_DATA)
		{
			maxThermalControllerIndex = iThermalControllerIndex - 1;
			break;
		}

		if (ADL_Err == ADL_WARNING_NO_DATA)
		{
		   puts("[!] Failed to enumerate thermal devices");
		   return -50;
		}			

		if (termalControllerInfo.iThermalDomain == ADL_DL_THERMAL_DOMAIN_GPU)
		{

			ADLTemperature adlTemperature = {0};
			adlTemperature.iSize = sizeof (ADLTemperature);

			if (ADL_OK != ADL_Overdrive6_Temperature_Get ( adapterId, iThermalControllerIndex, &adlTemperature ))
			{
				puts("[!] Failed to get thermal devices temperature");
				return 0;
			}


			// The temperature is returned in millidegrees Celsius.
			tempCelsius = adlTemperature.iTemperature / 1000;
			//printf ("[+] Current temperature: %d\n", tempCelsius);


		}	

	}


	return 0;
}



int fanRpmMax = 0;
int fanRpmMin = 0;
int fanRpmCurr = 0;

int fanProcentCurr = 0;
int fanProcentMax = 0;
int fanProcentMin = 0;

int GetInfoFanOd5(int adapterId, void* hDLL)
{

	ADL_Overdrive5_ThermalDevices_Enum = (ADL_OVERDRIVE5_THERMALDEVICES_ENUM) GetProcAddress (hDLL, "ADL_Overdrive5_ThermalDevices_Enum");

	ADL_Overdrive5_FanSpeed_Get = (ADL_OVERDRIVE5_FANSPEED_GET) GetProcAddress (hDLL, "ADL_Overdrive5_FanSpeed_Get");
	ADL_Overdrive5_FanSpeedInfo_Get = (ADL_OVERDRIVE5_FANSPEEDINFO_GET ) GetProcAddress (hDLL, "ADL_Overdrive5_FanSpeedInfo_Get");
			
	if (NULL == ADL_Overdrive5_ThermalDevices_Enum || NULL == ADL_Overdrive5_FanSpeedInfo_Get)
	{
       printf("ADL's API is missing!\n");
	   return 0; 
	}

	
	int  ADL_Err = ADL_ERR;
	int maxThermalControllerIndex = 0;
	ADLFanSpeedInfo fanSpeedInfo = {0};
	int fanSpeedReportingMethod = 0;


	ADLThermalControllerInfo termalControllerInfo = {0};
	termalControllerInfo.iSize = sizeof (ADLThermalControllerInfo);


	for (int iThermalControllerIndex = 0; iThermalControllerIndex < 10; iThermalControllerIndex++) 
	{
		ADL_Err = ADL_Overdrive5_ThermalDevices_Enum (adapterId, iThermalControllerIndex, &termalControllerInfo);			



		if (ADL_Err == ADL_WARNING_NO_DATA)
		{
			maxThermalControllerIndex = iThermalControllerIndex - 1;
			break;
		}



		if (ADL_Err == ADL_WARNING_NO_DATA)
		{
		   puts("[!] Failed to enumerate thermal devices");
		   return -50;
		}			



		if (termalControllerInfo.iThermalDomain == ADL_DL_THERMAL_DOMAIN_GPU)
		{

			
			fanSpeedInfo.iSize = sizeof (ADLFanSpeedInfo);

			if ( ADL_OK != ADL_Overdrive5_FanSpeedInfo_Get(adapterId, iThermalControllerIndex, &fanSpeedInfo))
			{
				puts("[!] Failed to get fan caps");
				return 0;
			}

			ADLFanSpeedValue fanSpeedValue = {0};
			fanSpeedReportingMethod = ((fanSpeedInfo.iFlags & ADL_DL_FANCTRL_SUPPORTS_RPM_READ) == ADL_DL_FANCTRL_SUPPORTS_RPM_READ )? ADL_DL_FANCTRL_SPEED_TYPE_RPM : ADL_DL_FANCTRL_SPEED_TYPE_PERCENT;
			
			//Set to ADL_DL_FANCTRL_SPEED_TYPE_RPM or to ADL_DL_FANCTRL_SPEED_TYPE_PERCENT to request fan speed to be returned in rounds per minute or in percentage points.
			//Note that the call might fail if requested fan speed reporting method is not supported by the GPU.
			fanSpeedValue.iSpeedType = fanSpeedReportingMethod; 

			if ( ADL_OK != ADL_Overdrive5_FanSpeed_Get (adapterId, iThermalControllerIndex, &fanSpeedValue))
			{
				puts("[+] Failed to get fan speed");
				return -10;
			}


			if (fanSpeedReportingMethod == ADL_DL_FANCTRL_SPEED_TYPE_RPM)
			{
				fanRpmMax = fanSpeedInfo.iMaxRPM;
				fanRpmMin = fanSpeedInfo.iMinRPM;
				fanRpmCurr = fanSpeedValue.iFanSpeed;
			}

				else
				{
					fanProcentMin = fanSpeedInfo.iMinPercent;
					fanProcentMax = fanSpeedInfo.iMaxPercent;
					fanProcentCurr = fanSpeedValue.iFanSpeed;
				}				
		}
	}

	return 0;


}





int GetInfoFanOd6(int adapterId, void* hDLL)
{

	ADL_Overdrive6_ThermalDevices_Enum = (ADL_OVERDRIVE6_THERMALDEVICES_ENUM) GetProcAddress (hDLL, "ADL_Overdrive6_ThermalDevices_Enum");

	ADL_Overdrive6_FanSpeed_Get = (ADL_OVERDRIVE6_FANSPEED_GET) GetProcAddress (hDLL, "ADL_Overdrive6_FanSpeed_Get");
	ADL_Overdrive5_FanSpeedInfo_Get = (ADL_OVERDRIVE5_FANSPEEDINFO_GET ) GetProcAddress (hDLL, "ADL_Overdrive6_FanSpeedInfo_Get");
			
	if (NULL == ADL_Overdrive6_ThermalDevices_Enum || NULL == ADL_Overdrive6_FanSpeedInfo_Get)
	{
       printf("ADL's API is missing!\n");
	   return 0; 
	}

	
	int  ADL_Err = ADL_ERR;
	int maxThermalControllerIndex = 0;
	ADLFanSpeedInfo fanSpeedInfo = {0};
	int fanSpeedReportingMethod = 0;


	ADLThermalControllerInfo termalControllerInfo = {0};
	termalControllerInfo.iSize = sizeof (ADLThermalControllerInfo);


	for (int iThermalControllerIndex = 0; iThermalControllerIndex < 10; iThermalControllerIndex++) 
	{
		ADL_Err = ADL_Overdrive6_ThermalDevices_Enum (adapterId, iThermalControllerIndex, &termalControllerInfo);			



		if (ADL_Err == ADL_WARNING_NO_DATA)
		{
			maxThermalControllerIndex = iThermalControllerIndex - 1;
			break;
		}



		if (ADL_Err == ADL_WARNING_NO_DATA)
		{
		   puts("[!] Failed to enumerate thermal devices");
		   return -50;
		}			



		if (termalControllerInfo.iThermalDomain == ADL_DL_THERMAL_DOMAIN_GPU)
		{

			
			fanSpeedInfo.iSize = sizeof (ADLFanSpeedInfo);

			if ( ADL_OK != ADL_Overdrive6_FanSpeedInfo_Get(adapterId, iThermalControllerIndex, &fanSpeedInfo))
			{
				puts("[!] Failed to get fan caps");
				return 0;
			}

			ADLFanSpeedValue fanSpeedValue = {0};
			fanSpeedReportingMethod = ((fanSpeedInfo.iFlags & ADL_DL_FANCTRL_SUPPORTS_RPM_READ) == ADL_DL_FANCTRL_SUPPORTS_RPM_READ )? ADL_DL_FANCTRL_SPEED_TYPE_RPM : ADL_DL_FANCTRL_SPEED_TYPE_PERCENT;
			
			//Set to ADL_DL_FANCTRL_SPEED_TYPE_RPM or to ADL_DL_FANCTRL_SPEED_TYPE_PERCENT to request fan speed to be returned in rounds per minute or in percentage points.
			//Note that the call might fail if requested fan speed reporting method is not supported by the GPU.
			fanSpeedValue.iSpeedType = fanSpeedReportingMethod; 

			if ( ADL_OK != ADL_Overdrive6_FanSpeed_Get (adapterId, iThermalControllerIndex, &fanSpeedValue))
			{
				puts("[+] Failed to get fan speed");
				return -10;
			}


			if (fanSpeedReportingMethod == ADL_DL_FANCTRL_SPEED_TYPE_RPM)
			{
				fanRpmMax = fanSpeedInfo.iMaxRPM;
				fanRpmMin = fanSpeedInfo.iMinRPM;
				fanRpmCurr = fanSpeedValue.iFanSpeed;
			}

				else
				{
					fanProcentMin = fanSpeedInfo.iMinPercent;
					fanProcentMax = fanSpeedInfo.iMaxPercent;
					fanProcentCurr = fanSpeedValue.iFanSpeed;
				}				
		}
	}

	return 0;


}
