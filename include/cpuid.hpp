#pragma once

enum class CPUFeature: unsigned
{
	MMX				= 0x0001,
	MWait			= 0x0002,
	HT				= 0x0004,

	SSE				= 0x0008,
	SSE2			= 0x0010,
	SSE3			= 0x0020,
	SSSE3			= 0x0030,
	SSE41			= 0x0040,
	SSE42			= 0x0050,

	AVX				= 0x0060,
	AVX2			= 0x0070,
	AVX512F			= 0x0080,
	AVX512PF		= 0x0090,
	AVX512ER		= 0x0100,
	AVX512CD		= 0x0200,

	AMD_3DNow		= 0x0300,
	AMD_3DNowExt	= 0x0400
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