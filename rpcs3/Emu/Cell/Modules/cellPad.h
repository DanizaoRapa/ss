#pragma once

#include "Emu/Io/pad_types.h"

#include <array>
#include "util/types.hpp"

enum CellPadError : u32
{
	CELL_PAD_ERROR_FATAL                      = 0x80121101,
	CELL_PAD_ERROR_INVALID_PARAMETER          = 0x80121102,
	CELL_PAD_ERROR_ALREADY_INITIALIZED        = 0x80121103,
	CELL_PAD_ERROR_UNINITIALIZED              = 0x80121104,
	CELL_PAD_ERROR_RESOURCE_ALLOCATION_FAILED = 0x80121105,
	CELL_PAD_ERROR_DATA_READ_FAILED           = 0x80121106,
	CELL_PAD_ERROR_NO_DEVICE                  = 0x80121107,
	CELL_PAD_ERROR_UNSUPPORTED_GAMEPAD        = 0x80121108,
	CELL_PAD_ERROR_TOO_MANY_DEVICES           = 0x80121109,
	CELL_PAD_ERROR_EBUSY                      = 0x8012110a,
};

enum CellPadFilterError : u32
{
	CELL_PADFILTER_ERROR_INVALID_PARAMETER = 0x80121401,
};

// Controller types
enum
{
	CELL_PAD_PCLASS_TYPE_STANDARD   = 0x00,
	CELL_PAD_PCLASS_TYPE_GUITAR     = 0x01,
	CELL_PAD_PCLASS_TYPE_DRUM       = 0x02,
	CELL_PAD_PCLASS_TYPE_DJ         = 0x03,
	CELL_PAD_PCLASS_TYPE_DANCEMAT   = 0x04,
	CELL_PAD_PCLASS_TYPE_NAVIGATION = 0x05,
};

// Profile of a Standard Type Controller
// Profile of a Navigation Type Controller
// Bits 0 – 31 All 0s

// Profile of a Guitar Type Controller
enum
{
	// Basic
	CELL_PAD_PCLASS_PROFILE_GUITAR_FRET_1       = 0x00000001,
	CELL_PAD_PCLASS_PROFILE_GUITAR_FRET_2       = 0x00000002,
	CELL_PAD_PCLASS_PROFILE_GUITAR_FRET_3       = 0x00000004,
	CELL_PAD_PCLASS_PROFILE_GUITAR_FRET_4       = 0x00000008,
	CELL_PAD_PCLASS_PROFILE_GUITAR_FRET_5       = 0x00000010,
	CELL_PAD_PCLASS_PROFILE_GUITAR_STRUM_UP     = 0x00000020,
	CELL_PAD_PCLASS_PROFILE_GUITAR_STRUM_DOWN   = 0x00000040,
	CELL_PAD_PCLASS_PROFILE_GUITAR_WHAMMYBAR    = 0x00000080,
	// All Basic                                = 0x000000FF

	// Optional
	CELL_PAD_PCLASS_PROFILE_GUITAR_FRET_H1      = 0x00000100,
	CELL_PAD_PCLASS_PROFILE_GUITAR_FRET_H2      = 0x00000200,
	CELL_PAD_PCLASS_PROFILE_GUITAR_FRET_H3      = 0x00000400,
	CELL_PAD_PCLASS_PROFILE_GUITAR_FRET_H4      = 0x00000800,
	CELL_PAD_PCLASS_PROFILE_GUITAR_FRET_H5      = 0x00001000,
	CELL_PAD_PCLASS_PROFILE_GUITAR_5WAY_EFFECT  = 0x00002000,
	CELL_PAD_PCLASS_PROFILE_GUITAR_TILT_SENS    = 0x00004000,
	// All                                      = 0x00007FFF
};

// Profile of a Drum Type Controller
enum
{
	CELL_PAD_PCLASS_PROFILE_DRUM_SNARE     = 0x00000001,
	CELL_PAD_PCLASS_PROFILE_DRUM_TOM       = 0x00000002,
	CELL_PAD_PCLASS_PROFILE_DRUM_TOM2      = 0x00000004,
	CELL_PAD_PCLASS_PROFILE_DRUM_TOM_FLOOR = 0x00000008,
	CELL_PAD_PCLASS_PROFILE_DRUM_KICK      = 0x00000010,
	CELL_PAD_PCLASS_PROFILE_DRUM_CYM_HiHAT = 0x00000020,
	CELL_PAD_PCLASS_PROFILE_DRUM_CYM_CRASH = 0x00000040,
	CELL_PAD_PCLASS_PROFILE_DRUM_CYM_RIDE  = 0x00000080,
	CELL_PAD_PCLASS_PROFILE_DRUM_KICK2     = 0x00000100,
	// All                                 = 0x000001FF
};

// Profile of a DJ Deck Type Controller
enum
{
	CELL_PAD_PCLASS_PROFILE_DJ_MIXER_ATTACK     = 0x00000001,
	CELL_PAD_PCLASS_PROFILE_DJ_MIXER_CROSSFADER = 0x00000002,
	CELL_PAD_PCLASS_PROFILE_DJ_MIXER_DSP_DIAL   = 0x00000004,
	CELL_PAD_PCLASS_PROFILE_DJ_DECK1_STREAM1    = 0x00000008,
	CELL_PAD_PCLASS_PROFILE_DJ_DECK1_STREAM2    = 0x00000010,
	CELL_PAD_PCLASS_PROFILE_DJ_DECK1_STREAM3    = 0x00000020,
	CELL_PAD_PCLASS_PROFILE_DJ_DECK1_PLATTER    = 0x00000040,
	CELL_PAD_PCLASS_PROFILE_DJ_DECK2_STREAM1    = 0x00000080,
	CELL_PAD_PCLASS_PROFILE_DJ_DECK2_STREAM2    = 0x00000100,
	CELL_PAD_PCLASS_PROFILE_DJ_DECK2_STREAM3    = 0x00000200,
	CELL_PAD_PCLASS_PROFILE_DJ_DECK2_PLATTER    = 0x00000400,
	// All                                      = 0x000007FF
};

// Profile of a Dance Mat Type Controller
enum
{
	CELL_PAD_PCLASS_PROFILE_DANCEMAT_CIRCLE   = 0x00000001,
	CELL_PAD_PCLASS_PROFILE_DANCEMAT_CROSS    = 0x00000002,
	CELL_PAD_PCLASS_PROFILE_DANCEMAT_TRIANGLE = 0x00000004,
	CELL_PAD_PCLASS_PROFILE_DANCEMAT_SQUARE   = 0x00000008,
	CELL_PAD_PCLASS_PROFILE_DANCEMAT_RIGHT    = 0x00000010,
	CELL_PAD_PCLASS_PROFILE_DANCEMAT_LEFT     = 0x00000020,
	CELL_PAD_PCLASS_PROFILE_DANCEMAT_UP       = 0x00000040,
	CELL_PAD_PCLASS_PROFILE_DANCEMAT_DOWN     = 0x00000080,
	// All                                    = 0x000000FF
};

// Length returned in CellPadData struct
enum
{
	CELL_PAD_LEN_NO_CHANGE = 0,
	CELL_PAD_LEN_CHANGE_DEFAULT = 8,
	CELL_PAD_LEN_CHANGE_PRESS_ON = 20,
	CELL_PAD_LEN_CHANGE_SENSOR_ON = 24,
};

enum
{
	CELL_PADFILTER_IIR_CUTOFF_2ND_LPF_BT_050 = 0, // 50% Nyquist frequency
	CELL_PADFILTER_IIR_CUTOFF_2ND_LPF_BT_020 = 1, // 20% Nyquist frequency
	CELL_PADFILTER_IIR_CUTOFF_2ND_LPF_BT_010 = 2, // 10% Nyquist frequency
};

struct CellPadInfo
{
	be_t<u32> max_connect;
	be_t<u32> now_connect;
	be_t<u32> system_info;
	be_t<u16> vendor_id[CELL_MAX_PADS];
	be_t<u16> product_id[CELL_MAX_PADS];
	u8 status[CELL_MAX_PADS];
};

struct CellPadInfo2
{
	be_t<u32> max_connect;
	be_t<u32> now_connect;
	be_t<u32> system_info;
	be_t<u32> port_status[CELL_PAD_MAX_PORT_NUM];
	be_t<u32> port_setting[CELL_PAD_MAX_PORT_NUM];
	be_t<u32> device_capability[CELL_PAD_MAX_PORT_NUM];
	be_t<u32> device_type[CELL_PAD_MAX_PORT_NUM];
};

struct CellPadPeriphInfo
{
	be_t<u32> max_connect;
	be_t<u32> now_connect;
	be_t<u32> system_info;
	be_t<u32> port_status[CELL_PAD_MAX_PORT_NUM];
	be_t<u32> port_setting[CELL_PAD_MAX_PORT_NUM];
	be_t<u32> device_capability[CELL_PAD_MAX_PORT_NUM];
	be_t<u32> device_type[CELL_PAD_MAX_PORT_NUM];
	be_t<u32> pclass_type[CELL_PAD_MAX_PORT_NUM];
	be_t<u32> pclass_profile[CELL_PAD_MAX_PORT_NUM];
};

struct CellPadPeriphData
{
	be_t<u32> pclass_type;
	be_t<u32> pclass_profile;
	CellPadData cellpad_data;
};

struct CellPadCapabilityInfo
{
	be_t<u32> info[CELL_PAD_MAX_CAPABILITY_INFO];
};

struct CellPadActParam
{
	u8 motor[CELL_PAD_ACTUATOR_MAX];
	u8 reserved[6];
};

struct CellPadFilterIIRSos
{
	be_t<s32> u[3];
	be_t<s32> a1;
	be_t<s32> a2;
	be_t<s32> b0;
	be_t<s32> b1;
	be_t<s32> b2;
};

struct pad_info
{
	atomic_t<u32> max_connect = 0;
	std::array<u32, CELL_PAD_MAX_PORT_NUM> port_setting{ 0 };
	std::array<u32, CELL_PAD_MAX_PORT_NUM> reported_statuses{};

	SAVESTATE_INIT_POS(11);

	pad_info() = default;
	pad_info(utils::serial& ar);
	void save(utils::serial& ar);

	u32 get_max_connect() const
	{
		return std::min<u32>(max_connect, CELL_PAD_MAX_PORT_NUM);
	}

	// Unreliable way the firmware uses to optimize away pad calls for disconnected pads
	// This result relies on data updates from config events on a dedicated thread to receive them
	bool is_reportedly_connected(u32 port_no) const
	{
		return port_no < get_max_connect() && !!(reported_statuses[port_no] & CELL_PAD_STATUS_CONNECTED);
	}
};

error_code cellPadGetData(u32 port_no, vm::ptr<CellPadData> data);
error_code cellPadInit(ppu_thread& ppu, u32 max_connect);
error_code cellPadSetPortSetting(u32 port_no, u32 port_setting);
