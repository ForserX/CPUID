#pragma once

enum class CPUFeature : unsigned 
{
	MMX		= 0x0001,
	MWait,
	HT,

	SSE,
	SSE2,
	SSE3,
	SSSE3,
	SSE41,
	SSE42,
	
	AVX,
	AVX2,
	AVX512F,
	AVX512PF,
	AVX512ER,
	AVX512CD,

	AMD_3DNow,
	AMD_3DNowExt
};

struct processor_info 
{
	processor_info();

	unsigned char family;	// family of the processor, eg. Intel_Pentium_Pro is family 6 processor
	unsigned char model;	// model of processor, eg. Intel_Pentium_Pro is model 1 of family 6 processor
	unsigned char stepping; // Processor revision number

	bool isAmd;				// AMD flag
	bool isIntel;			// IntelCore flag
#ifdef _M_IX86 
	bool WoW64;				// WoW64 flag
#endif
	char vendor[32];
	char modelName[64];

	unsigned features;		// processor Feature ( same as return value).

	unsigned n_cores;		// number of available physical cores
	unsigned n_threads;		// number of available logical threads

	unsigned affinity_mask; // recommended affinity mask
								// all processors available to process
								// except 2nd (and upper) logical threads
								// of the same physical core

	bool hasFeature(const CPUFeature feature) const noexcept
	{
		return (features & static_cast<unsigned>(feature));
	}

};

unsigned query_processor_info(processor_info*);