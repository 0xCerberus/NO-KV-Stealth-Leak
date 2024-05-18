#ifndef __XAMEXT_XCONTENT_H
#define __XAMEXT_XCONTENT_H

#define XCONTENT_FILE_SYSTEM_ALIGNMENT              (4 * 1024)
#define XCONTENT_ROUND_UP_TO_ALIGNMENT(size)        (((size) + (XCONTENT_FILE_SYSTEM_ALIGNMENT - 1)) & (~(XCONTENT_FILE_SYSTEM_ALIGNMENT - 1)))
#define XCONTENT_ALIGNMENT_PADDING_NEEDED(size)     (XCONTENT_ROUND_UP_TO_ALIGNMENT(size) - (size))

#define XCONTENT_UNRESTRICTED_LICENSEE          ((ULONGLONG) 0xFFFFFFFFFFFFFFFFULL)
#define XCONTENT_LICENSE_FLAG_REQUIRE_ONLINE    0x00000001

// some flags for mounting CON/LIVE/PIRS using mountCon/XamContentOpenFile
#define XCONTENT_ANY_USER								0xFF
#define XCONTENT_PKGFLAG_KEEP_OPEN_ON_TITLE_TERMINATE 	0x00000001
#define XCONTENT_PKGFLAG_DONT_UPDATE_DIGESTS_ON_CLOSE 	0x00000002
#define XCONTENT_FLAG_ATTRIBUTE_DEVICE					FILE_ATTRIBUTE_DEVICE
#define XCONTENT_OPENPKG_DONT_VERIFY_SIGNATURE 			0x00010000
#define XCONTENT_OPENPKG_COPY_EXISTING_HANDLE 			0x00020000
#define XCONTENT_FLAG_EXECUTE 							0x04000000

// some combined flags for often used operations
#define XCONTENT_MOUNT_FOR_READ_ONLY					(XCONTENT_FLAG_ATTRIBUTE_DEVICE|XCONTENT_PKGFLAG_DONT_UPDATE_DIGESTS_ON_CLOSE)
#define XCONTENT_MOUNT_FOR_EXEC							(XCONTENT_FLAG_EXECUTE|XCONTENT_FLAG_ATTRIBUTE_DEVICE| \
														XCONTENT_PKGFLAG_DONT_UPDATE_DIGESTS_ON_CLOSE| \
														XCONTENT_PKGFLAG_KEEP_OPEN_ON_TITLE_TERMINATE)

#pragma warning(push)
#pragma warning(disable:4005) // Get rid of the redefinition warning
#define XCONTENTTYPE_SAVEDGAME					0x00000001
#define XCONTENTTYPE_MARKETPLACE				0x00000002
#define XCONTENTTYPE_PUBLISHER					0x00000003
#define XCONTENTTYPE_IPTV_DVR					0x00001000
#define XCONTENTTYPE_INSTALLED_XBOX360TITLE		0x00004000
#define XCONTENTTYPE_XBOXTITLE					0x00005000
#define XCONTENTTYPE_SOCIALTITLE				0x00006000
#define XCONTENTTYPE_XBOX360TITLE				0x00007000
#define XCONTENTTYPE_SU_STORAGEPACK				0x00008000
#define XCONTENTTYPE_AVATAR_ASSET				0x00009000
#define XCONTENTTYPE_PROFILE					0x00010000
#define XCONTENTTYPE_ADDON						0x00020000
#define XCONTENTTYPE_THEMATICSKIN				0x00030000
#define XCONTENTTYPE_CACHE						0x00040000
#define XCONTENTTYPE_STORAGEDOWNLOAD			0x00050000
#define XCONTENTTYPE_XBOXSAVEDGAME				0x00060000
#define XCONTENTTYPE_XBOXDOWNLOAD				0x00070000
#define XCONTENTTYPE_GAMEDEMO					0x00080000
#define XCONTENTTYPE_VIDEO						0x00090000
#define XCONTENTTYPE_GAMETITLE					0x000A0000
#define XCONTENTTYPE_INSTALLER					0x000B0000
#define XCONTENTTYPE_GAMETRAILER				0x000C0000
#define XCONTENTTYPE_ARCADE						0x000D0000
#define XCONTENTTYPE_XNA						0x000E0000
#define XCONTENTTYPE_LICENSESTORE				0x000F0000
#define XCONTENTTYPE_MOVIE						0x00100000
#define XCONTENTTYPE_TV							0x00200000
#define XCONTENTTYPE_MUSICVIDEO					0x00300000
#define XCONTENTTYPE_PROMOTIONAL				0x00400000
#define XCONTENTTYPE_PODCASTVIDEO				0x00500000
#define XCONTENTTYPE_VIRALVIDEO					0x00600000

// languages for the DisplayName and Description fields
#define XCONTENT_METADATA_LANG_ENGLISH		0
#define XCONTENT_METADATA_LANG_JAPANESE		1
#define XCONTENT_METADATA_LANG_GERMAN		2
#define XCONTENT_METADATA_LANG_FRENCH		3
#define XCONTENT_METADATA_LANG_SPANISH		4
#define XCONTENT_METADATA_LANG_ITALIAN		5
#define XCONTENT_METADATA_LANG_KOREAN		6
#define XCONTENT_METADATA_LANG_CHINESE_TR	7 // chinese traditional
#define XCONTENT_METADATA_LANG_PORTUGESE	8
#define XCONTENT_METADATA_LANG_MAX			9

// languages for the DisplayNameEx and DescriptionEx fields
#define XCONTENT_METADATA_LANG_EX_RUSSIAN	0
#define XCONTENT_METADATA_LANG_EX_POLISH	1
#define XCONTENT_METADATA_LANG_EX_UNKNOWN	2
#define XCONTENT_METADATA_LANG_EX_MAX		3


#define XCONTENTDEVICETYPE_NONE         ((XCONTENTDEVICETYPE)0x0)
#define XCONTENTDEVICETYPE_HDD          ((XCONTENTDEVICETYPE)0x1) // in the sdk
#define XCONTENTDEVICETYPE_MU           ((XCONTENTDEVICETYPE)0x2) // in the sdk
#define XCONTENTDEVICETYPE_SYSTEMMU     ((XCONTENTDEVICETYPE)0x3)
#define XCONTENTDEVICETYPE_ODD          ((XCONTENTDEVICETYPE)0x4) // in the sdk
#define XCONTENTDEVICETYPE_XFERCABLE	((XCONTENTDEVICETYPE)0x8)
#define XCONTENTDEVICETYPE_USBMASS      ((XCONTENTDEVICETYPE)0x10)

// This flag is OR'd into a device type if the device is unformatted
#define XCONTENTDEVICEFLAG_UNFORMATTED  ((XCONTENTDEVICETYPE)0x80000000)
// This flag can be supplied to XContentCreateDeviceEnumerator to enumerate
// USB mass storage devices
#define XCONTENTDEVICEFLAG_USBMASS      (0x40000000)
#define XCONTENTDEVICE_ALL				(0xFFFFFFFF)

#define SU_PACKAGE	  					"su20076000_00000000"
#define MAGIC_XSYM 						((u32)0x7873796D) // 'xsym'
#define MAGIC_XONM 						((u32)0x786F6E6D) // 'xonm'
#define MAGIC_XMNP 						((u32)0x584D4E50) // 'XMNP'

#pragma warning(pop)

typedef enum { // LICENSEE_TYPE 
	LICENSEE_TYPE_WINDOWS_ID = 0x3, // not sure on this one (velocity)
	LICENSEE_TYPE_XUID = 0x9,
	LICENSEE_TYPE_USER_PRIVILEGES = 0xB000,
	LICENSEE_TYPE_HV_FLAGS = 0xC000,
	LICENSEE_TYPE_KEY_VAULT_PRIVILEGES = 0xD000,
	LICENSEE_TYPE_MEDIA_FLAGS = 0xE000,
	LICENSEE_TYPE_CONSOLE_ID = 0xF000,
};
typedef enum XCONTENT_VOLUME_TYPE {
	STFS_VOLUME = 0x0,
	SVOD_VOLUME = 0x1,
};

typedef enum _XCONTENT_SIGNATURE_TYPE {
	CONSOLE_SIGNED = 0x434F4E20,
	LIVE_SIGNED    = 0x4C495645,
	PIRS_SIGNED    = 0x50495253,
} XCONTENT_SIGNATURE_TYPE;

typedef enum _INSTALLER_METADATA_TYPE {
	INSTALLER_METADATA_UNDEFINED = 0,
	INSTALLER_METADATA_TYPE_PROGRESS_CACHE_PACKAGE_DOWNLOAD = 0x50245044,
	INSTALLER_METADATA_TYPE_PROGRESS_CACHE_SYSTEM_UPDATE = 0x50245355,
	INSTALLER_METADATA_TYPE_PROGRESS_CACHE_TITLE_CONTENT = 0x50245443,
	INSTALLER_METADATA_TYPE_PROGRESS_CACHE_TITLE_UPDATE = 0x50245455,
	INSTALLER_METADATA_TYPE_SYSTEM_UPDATE = 0x53555044,
	INSTALLER_METADATA_TYPE_TITLE_UPDATE = 0x54555044,
} INSTALLER_METADATA_TYPE;

typedef enum _XONLINECONTENT_RESUME_STATE {
	XONLINECONTENT_RESUME_STATE_FILE_HEADERS_NOT_READY = 0x46494C48,
	XONLINECONTENT_RESUME_STATE_LEGACY_NEW_FOLDER = 0x464F4C44,
	XONLINECONTENT_RESUME_STATE_LEGACY_NEW_FOLDER_ATTEMPT_2 = 0x464F4C32,
	XONLINECONTENT_RESUME_STATE_LEGACY_NEW_FOLDER_ATTEMPT_3 = 0x464F4C33,
	XONLINECONTENT_RESUME_STATE_NEW_FOLDER = 0x666F6C64,
	XONLINECONTENT_RESUME_STATE_NEW_FOLDER_RESUME_ATTEMPT_2 = 0x666F6C32,
	XONLINECONTENT_RESUME_STATE_NEW_FOLDER_RESUME_ATTEMPT_3 = 0x666F6C33,
	XONLINECONTENT_RESUME_STATE_NEW_FOLDER_RESUME_ATTEMPT_4 = 0x666F6C34,
	XONLINECONTENT_RESUME_STATE_NEW_FOLDER_RESUME_ATTEMPT_5 = 0x666F6C35,
	XONLINECONTENT_RESUME_STATE_NEW_FOLDER_RESUME_ATTEMPT_6 = 0x666F6C36,
	XONLINECONTENT_RESUME_STATE_NEW_FOLDER_RESUME_ATTEMPT_7 = 0x666F6C37,
	XONLINECONTENT_RESUME_STATE_NEW_FOLDER_RESUME_ATTEMPT_8 = 0x666F6C38,
	XONLINECONTENT_RESUME_STATE_NEW_FOLDER_RESUME_ATTEMPT_9 = 0x666F6C39,
	XONLINECONTENT_RESUME_STATE_NEW_FOLDER_RESUME_ATTEMPT_10 = 0x666F6C3A,
	XONLINECONTENT_RESUME_STATE_NEW_FOLDER_RESUME_ATTEMPT_11 = 0x666F6C3B,
	XONLINECONTENT_RESUME_STATE_NEW_FOLDER_RESUME_ATTEMPT_12 = 0x666F6C3C,
	XONLINECONTENT_RESUME_STATE_NEW_FOLDER_RESUME_ATTEMPT_13 = 0x666F6C3D,
	XONLINECONTENT_RESUME_STATE_NEW_FOLDER_RESUME_ATTEMPT_14 = 0x666F6C3E,
	XONLINECONTENT_RESUME_STATE_NEW_FOLDER_RESUME_ATTEMPT_15 = 0x666F6C3F,
	XONLINECONTENT_RESUME_STATE_NEW_FOLDER_RESUME_ATTEMPT_16 = 0x666F6C40,
}XONLINECONTENT_RESUME_STATE;

typedef enum _XMARKETPLACE_MEDIA_TYPE {
	XMARKETPLACE_MEDIA_TYPE_UNKNOWN = 0x0,
	XMARKETPLACE_MEDIA_TYPE_360_GAME = 0x1,
	XMARKETPLACE_MEDIA_TYPE_MOVIE = 0x2,
	XMARKETPLACE_MEDIA_TYPE_TVSHOW = 0x3,
	XMARKETPLACE_MEDIA_TYPE_MUSIC_VIDEO = 0x4,
	XMARKETPLACE_MEDIA_TYPE_ARCADE_DEMO = 0x5,
	XMARKETPLACE_MEDIA_TYPE_VIRAL_VIDEO = 0x7,
	XMARKETPLACE_MEDIA_TYPE_TV_EPISODE = 0x8,
	XMARKETPLACE_MEDIA_TYPE_TV_SEASON = 0x9,
	XMARKETPLACE_MEDIA_TYPE_TV_SERIES = 0xA,
	XMARKETPLACE_MEDIA_TYPE_IN_GAME_CONTENT = 0x12,
	XMARKETPLACE_MEDIA_TYPE_GAME_DEMO = 0x13,
	XMARKETPLACE_MEDIA_TYPE_360_THEME = 0x14,
	XMARKETPLACE_MEDIA_TYPE_XBOX1_GAME = 0x15,
	XMARKETPLACE_MEDIA_TYPE_GAMER_PICTURE = 0x16,
	XMARKETPLACE_MEDIA_TYPE_ARCADE_GAME = 0x17,
	XMARKETPLACE_MEDIA_TYPE_IN_GAME_CONSUMABLE = 0x18,
	XMARKETPLACE_MEDIA_TYPE_GAME_VIDEO = 0x1E,
	XMARKETPLACE_MEDIA_TYPE_GAME_TRAILER = 0x22,
	XMARKETPLACE_MEDIA_TYPE_MARKETPLACE_BUNDLE = 0x24,
	XMARKETPLACE_MEDIA_TYPE_COMMUNITY_GAME = 0x25,
	XMARKETPLACE_MEDIA_TYPE_PROMOTIONAL_VIDEO = 0x27,
	XMARKETPLACE_MEDIA_TYPE_MOVIE_TRAILER = 0x28,
	XMARKETPLACE_MEDIA_TYPE_MARKETPLACE_CONTENT = 0x2E,
	XMARKETPLACE_MEDIA_TYPE_AVATAR_ITEM = 0x2F,
	XMARKETPLACE_MEDIA_TYPE_APP = 0x3D,
}XMARKETPLACE_MEDIA_TYPE;

// *********** PACKING STARTS HERE **************//
#pragma pack(push, 1)
// *********** PACKING STARTS HERE **************//
typedef struct _SU_MAINIFEST_HEADER {
	DWORD dwMagic; // 0 'XMNP'
	BYTE baUnk1[0x20]; // 0x4
	BYTE baDataSha[0x14]; // 0x24
	BYTE baSignature[0x100]; // 0x38
}SU_MAINIFEST_HEADER, *PSU_MAINIFEST_HEADER; // sz 0x138
C_ASSERT(sizeof(SU_MAINIFEST_HEADER) == 0x138);

typedef struct _SU_CONTENT_HEADER {
	DWORD dwMagic; // 0x0 'xsym' or 'xonm'
	DWORD size; // 0x4
	DWORD unk1; // 0x8 must be 1?
	DWORD unk2; // 0xC
	DWORD dwSchemaVer; // 0x10
	DWORD dwFlashVer; // 0x14
	QWORD qwTimeStamp; // 0x18
	BYTE pad[8]; // 0x20
} SU_CONTENT_HEADER, *PSU_CONTENT_HEADER; // sz 0x28
C_ASSERT(sizeof(SU_CONTENT_HEADER) == 0x28);

typedef struct _SU_ITEM_ENTRY {
	DWORD dwSrcNameOff; // 0 source name
	DWORD dwPad1; // 0x4
	DWORD dwFileSize; // 0x8
	DWORD dwVersionOff; // 0xC pointer to version, used for folder on non-containers
	DWORD dwFlags; // 0x10 flags?
	DWORD dwPad2; // 0x14
	DWORD dwEntryType; // 0x18
	DWORD dwIntNameOff; // 0x1C internal name?
	DWORD dwDestNameOff; // 0x20 destination name
	BYTE contHash[0x14]; // 0x24
	BYTE dataHash[0x14]; // 0x38
	DWORD dwContentType; // 0x4C ie 0x00008000
	DWORD dwContentTitleId; // 0x50 ie 0xFFFE07DF
	DWORD dwPad3; // 0x54
	DWORD dwPad4; // 0x58
	DWORD dwXContItemListOff; // 0x5C num items in container, followed by entry offsets for each item
} SU_ITEM_ENTRY, *PSU_ITEM_ENTRY; // sz 0x60
C_ASSERT(sizeof(SU_ITEM_ENTRY) == 0x60);

typedef struct _SU_ITEM_LIST {
	DWORD dwSizeOfStruct;
	DWORD dwNumEntries;
	SU_ITEM_ENTRY ents[1];
} SU_ITEM_LIST, *PSU_ITEM_LIST; // sz 0x68
C_ASSERT(sizeof(SU_ITEM_LIST) == 0x68);

typedef struct _SU_MANIFEST_BODY {
	SU_CONTENT_HEADER cont;
	SU_ITEM_LIST items;
} SU_MANIFEST_BODY, *PSU_MANIFEST_BODY;

typedef struct _SU_MANIFEST {
	SU_MAINIFEST_HEADER header;
	SU_MANIFEST_BODY body;
} SU_MANIFEST, *PSU_MANIFEST;

typedef struct _XCONTENT_SIGNATURE { 
	BYTE Signature[0x100]; // 0x0 sz:0x100
	BYTE Reserved[0x128]; // 0x100 sz:0x128
} XCONTENT_SIGNATURE, *PXCONTENT_SIGNATURE; // size 552
C_ASSERT(sizeof(XCONTENT_SIGNATURE) == 0x228);

typedef struct _LICENSEE_BITS {
	USHORT Type;
	USHORT DataHi;
	ULONG DataLo;
	//UINT64 Type : 16; // 0x0 bfo:0x48
	//UINT64 Data : 48; // 0x0 bfo:0x0
} LICENSEE_BITS, *PLICENSEE_BITS; // size 8
C_ASSERT(sizeof(LICENSEE_BITS) == 0x8);

typedef union _LICENSEE { 
	LICENSEE_BITS Bits; // 0x0 sz:0x8
	UINT64 AsULONGLONG; // 0x0 sz:0x8
} LICENSEE, *PLICENSEE; // size 8
C_ASSERT(sizeof(LICENSEE) == 0x8);

typedef struct _XCONTENT_LICENSE { 
	LICENSEE LicenseeId; // 0 16bits type, 48bits data
	DWORD LicenseBits; // 8
	DWORD LicenseFlags; // 12
} XCONTENT_LICENSE, *PXCONTENT_LICENSE; // 16
C_ASSERT(sizeof(XCONTENT_LICENSE) == 16);

#define XCONTENT_HEADER_LICENSES	0x10
typedef struct _XCONTENT_HEADER { 
	XCONTENT_SIGNATURE_TYPE SignatureType; // 0
	union { // 4 sz: 0x228
		XE_CONSOLE_SIGNATURE ConsoleSignature;
		XCONTENT_SIGNATURE   ContentSignature;
	} Signature;
	XCONTENT_LICENSE LicenseDescriptors[XCONTENT_HEADER_LICENSES]; // 556
	BYTE ContentId[20]; // 812
	DWORD SizeOfHeaders; // 832
} XCONTENT_HEADER, *PXCONTENT_HEADER; // 836
C_ASSERT(sizeof(XCONTENT_HEADER) == 836); // XCONTENT_METADATA normally follows directly after

typedef struct _STF_VOLUME_DESCRIPTOR { 
	BYTE DescriptorLength; // 0x0 sz:0x1
	BYTE Version; // 0x1 sz:0x1
	BYTE ReadOnlyFormat : 1; // 0x2 bfo:0x0
	BYTE RootActiveIndex : 1; // 0x2 bfo:0x1
	BYTE DirectoryOverallocated : 1; // 0x2 bfo:0x2
	BYTE DirectoryIndexBoundsValid : 1; // 0x2 bfo:0x3
	BYTE DirectoryAllocationBlocks0; // 0x3 sz:0x1
	BYTE DirectoryAllocationBlocks1; // 0x4 sz:0x1
	BYTE DirectoryFirstBlockNumber0; // 0x5 sz:0x1
	BYTE DirectoryFirstBlockNumber1; // 0x6 sz:0x1
	BYTE DirectoryFirstBlockNumber2; // 0x7 sz:0x1
	BYTE RootHash[0x14]; // 0x8 sz:0x14
	DWORD NumberOfTotalBlocks; // 0x1C sz:0x4
	DWORD NumberOfFreeBlocks; // 0x20 sz:0x4
} STF_VOLUME_DESCRIPTOR, *PSTF_VOLUME_DESCRIPTOR; // size 36
C_ASSERT(sizeof(STF_VOLUME_DESCRIPTOR) == 0x24);

typedef struct _SVOD_HASH_ENTRY { 
	BYTE Hash[0x14]; // 0x0 sz:0x14
} SVOD_HASH_ENTRY, *PSVOD_HASH_ENTRY; // size 20
C_ASSERT(sizeof(SVOD_HASH_ENTRY) == 0x14);

typedef struct _SVOD_DEVICE_FEATURES { 
	BYTE ShouldBeZeroForDownlevelClients : 1; // 0x0 bfo:0x7
	BYTE HasEnhancedGDFLayout : 1; // 0x0 bfo:0x6
	BYTE MustBeZeroForFutureUsage : 6; // 0x0 bfo:0x0
} SVOD_DEVICE_FEATURES, *PSVOD_DEVICE_FEATURES; // size 1
C_ASSERT(sizeof(SVOD_DEVICE_FEATURES) == 0x1);

typedef struct _SVOD_DEVICE_DESCRIPTOR { 
	BYTE DescriptorLength; // 0x0 sz:0x1
	BYTE BlockCacheElementCount; // 0x1 sz:0x1
	BYTE WorkerThreadProcessor; // 0x2 sz:0x1
	BYTE WorkerThreadPriority; // 0x3 sz:0x1
	SVOD_HASH_ENTRY FirstFragmentHashEntry; // 0x4 sz:0x14
	SVOD_DEVICE_FEATURES Features; // 0x18 sz:0x1
	BYTE NumberOfDataBlocks2; // 0x19 sz:0x1
	BYTE NumberOfDataBlocks1; // 0x1A sz:0x1
	BYTE NumberOfDataBlocks0; // 0x1B sz:0x1
	BYTE StartingDataBlock0; // 0x1C sz:0x1
	BYTE StartingDataBlock1; // 0x1D sz:0x1
	BYTE StartingDataBlock2; // 0x1E sz:0x1
	BYTE Reserved[0x5]; // 0x1F sz:0x5
} SVOD_DEVICE_DESCRIPTOR, *PSVOD_DEVICE_DESCRIPTOR; // size 36
C_ASSERT(sizeof(SVOD_DEVICE_DESCRIPTOR) == 0x24);

typedef struct _XCONTENT_METADATA_MEDIA_DATA { 
	BYTE SeriesId[0x10]; // 0x0 sz:0x10
	BYTE SeasonId[0x10]; // 0x10 sz:0x10
	WORD SeasonNumber; // 0x20 sz:0x2
	WORD EpisodeNumber; // 0x22 sz:0x2
} XCONTENT_METADATA_MEDIA_DATA, *PXCONTENT_METADATA_MEDIA_DATA; // size 36
C_ASSERT(sizeof(XCONTENT_METADATA_MEDIA_DATA) == 0x24);

typedef struct _XCONTENT_METADATA_AVATAR_ASSET_DATA { 
	DWORD SubCategory; // 0x0 sz:0x4
	DWORD Colorizable; // 0x4 sz:0x4
	BYTE AssetId[0x10]; // 0x8 sz:0x10
	BYTE SkeletonVersionMask; // 0x18 sz:0x1
	BYTE Reserved[0xB]; // 0x19 sz:0xB
} XCONTENT_METADATA_AVATAR_ASSET_DATA, *PXCONTENT_METADATA_AVATAR_ASSET_DATA; // size 36
C_ASSERT(sizeof(XCONTENT_METADATA_AVATAR_ASSET_DATA) == 0x24);

typedef struct _XCONTENT_ATTRIBUTES { 
	BYTE Reserved : 2; // 0x0 bfo:0x0
	BYTE DeepLinkSupported : 1; // 0x0 bfo:0x2
	BYTE DisableNetworkStorage : 1; // 0x0 bfo:0x3
	BYTE KinectEnabled : 1; // 0x0 bfo:0x4
	BYTE MoveOnlyTransfer : 1; // 0x0 bfo:0x5
	BYTE DeviceTransfer : 1; // 0x0 bfo:0x6
	BYTE ProfileTransfer : 1; // 0x0 bfo:0x7
} XCONTENT_ATTRIBUTES, *PXCONTENT_ATTRIBUTES; // size 1
C_ASSERT(sizeof(XCONTENT_ATTRIBUTES) == 0x1);

typedef union _XCONTENT_METADATA_FLAGS { 
	XCONTENT_ATTRIBUTES Bits; // 0x0 sz:0x1
	BYTE FlagsAsBYTE; // 0x0 sz:0x1
} XCONTENT_METADATA_FLAGS, *PXCONTENT_METADATA_FLAGS; // size 1
C_ASSERT(sizeof(XCONTENT_METADATA_FLAGS) == 0x1);

typedef struct _XCONTENT_METADATA { 
	DWORD ContentType; // 0x0 sz:0x4
	DWORD ContentMetadataVersion; // 0x4 sz:0x4
	LARGE_INTEGER ContentSize; // 0x8 sz:0x8
	XEX_EXECUTION_ID ExecutionId; // 0x10 sz:0x18
	BYTE ConsoleId[0x5]; // 0x28 sz:0x5
	QWORD Creator; // 0x2D sz:0x8
	union {
		STF_VOLUME_DESCRIPTOR StfsVolumeDescriptor; // 0x35 sz:0x24
		SVOD_DEVICE_DESCRIPTOR SvodVolumeDescriptor; // 0x35 sz:0x24
	} Volume;
	DWORD DataFiles; // 0x59 sz:0x4
	QWORD DataFilesSize; // 0x5D sz:0x8
	enum XCONTENT_VOLUME_TYPE VolumeType; // 0x65 sz:0x4
	QWORD OnlineCreator; // 0x69 sz:0x8
	DWORD Category; // 0x71 sz:0x4
	BYTE Reserved2[0x20]; // 0x75 sz:0x20
	union {
		XCONTENT_METADATA_MEDIA_DATA MediaData; // 0x95 sz:0x24
		XCONTENT_METADATA_AVATAR_ASSET_DATA AvatarAssetData; // 0x95 sz:0x24
	} Data;
	BYTE DeviceId[0x14]; // 0xB9 sz:0x14
	WCHAR DisplayName[0x9][0x80]; // 0xCD sz:0x900
	WCHAR Description[0x9][0x80]; // 0x9CD sz:0x900
	WCHAR Publisher[0x40]; // 0x12CD sz:0x80
	WCHAR TitleName[0x40]; // 0x134D sz:0x80
	XCONTENT_METADATA_FLAGS Flags; // 0x13CD sz:0x1
	DWORD ThumbnailSize; // 0x13CE sz:0x4
	DWORD TitleThumbnailSize; // 0x13D2 sz:0x4
	BYTE Thumbnail[0x3D00]; // 0x13D6 sz:0x3D00
	WCHAR DisplayNameEx[3][0x80]; // 0x50D6 sz:0x300
	BYTE TitleThumbnail[0x3D00]; // 0x53D6 sz:0x3D00
	WCHAR DescriptionEx[3][0x80]; // 0x90D6 sz:0x300
} XCONTENT_METADATA, *PXCONTENT_METADATA; // size 37846
C_ASSERT(sizeof(XCONTENT_METADATA) == 0x93D6);

typedef struct _XCONTENT_METADATA_INSTALLER_TITLE_UPDATE { 
	DWORD CurrentVersion; // 0x0 sz:0x4
	DWORD NewVersion; // 0x4 sz:0x4
	BYTE Reserved[0x15E8]; // 0x8 sz:0x15E8
} XCONTENT_METADATA_INSTALLER_TITLE_UPDATE, *PXCONTENT_METADATA_INSTALLER_TITLE_UPDATE; // size 5616
C_ASSERT(sizeof(XCONTENT_METADATA_INSTALLER_TITLE_UPDATE) == 0x15F0);

typedef struct _XCONTENT_METADATA_INSTALLER_SYSTEM_UPDATE { 
	DWORD SystemVersion; // 0x0 sz:0x4
	DWORD NewVersion; // 0x4 sz:0x4
	BYTE Reserved[0x15E8]; // 0x8 sz:0x15E8
} XCONTENT_METADATA_INSTALLER_SYSTEM_UPDATE, *PXCONTENT_METADATA_INSTALLER_SYSTEM_UPDATE; // size 5616
C_ASSERT(sizeof(XCONTENT_METADATA_INSTALLER_SYSTEM_UPDATE) == 0x15F0);

typedef struct _XONLINECONTENT_RESUME_HEADER { 
	XONLINECONTENT_RESUME_STATE ResumeState; // 0x0 sz:0x4
	DWORD dwCurrentFileIndex; // 0x4 sz:0x4
	LARGE_INTEGER liCurrentFileOffset; // 0x8 sz:0x8
	LARGE_INTEGER liBytesProcessed; // 0x10 sz:0x8
	LARGE_INTEGER liLastModified; // 0x18 sz:0x8
} XONLINECONTENT_RESUME_HEADER, *PXONLINECONTENT_RESUME_HEADER; // size 32
C_ASSERT(sizeof(XONLINECONTENT_RESUME_HEADER) == 0x20);

typedef struct _XCONTENT_METADATA_INSTALLER_PROGRESS_CACHE { 
	struct _XONLINECONTENT_RESUME_HEADER ResumeHeader; // 0x0 sz:0x20
	BYTE CabResumeData[0x15D0]; // 0x20 sz:0x15D0
} XCONTENT_METADATA_INSTALLER_PROGRESS_CACHE, *PXCONTENT_METADATA_INSTALLER_PROGRESS_CACHE; // size 5616
C_ASSERT(sizeof(XCONTENT_METADATA_INSTALLER_PROGRESS_CACHE) == 0x15F0);

typedef struct _XCONTENT_METADATA_INSTALLER { 
	INSTALLER_METADATA_TYPE MetaDataType; // 0x0 sz:0x4
	union {
		XCONTENT_METADATA_INSTALLER_TITLE_UPDATE TitleUpdate;
		XCONTENT_METADATA_INSTALLER_SYSTEM_UPDATE SystemUpdate;
		XONLINECONTENT_RESUME_HEADER ResumeHeader;
	}MetaData; // 0x4 sz:0x15F0
} XCONTENT_METADATA_INSTALLER, *PXCONTENT_METADATA_INSTALLER; // size 5620
C_ASSERT(sizeof(XCONTENT_METADATA_INSTALLER) == 0x15F4);

typedef struct _XCONTENT_METADATA_TITLE_CONTENT { 
	UCHAR Reserved[0x15F4]; // 0x0 sz:0x15F4
} XCONTENT_METADATA_TITLE_CONTENT, *PXCONTENT_METADATA_TITLE_CONTENT; // size 5620
C_ASSERT(sizeof(XCONTENT_METADATA_TITLE_CONTENT) == 0x15F4);

/* a typedef for all the header parts ONLY if they come one after the other!!! */
typedef struct _XCONTENT_FULL_HEADER {
	XCONTENT_HEADER Header; // 0x0 sz:0x344
	XCONTENT_METADATA Meta; // 0x344 sz:0x93D6
	union { // 0x971A sz:0x15F4
		XCONTENT_METADATA_INSTALLER Installer;
		XCONTENT_METADATA_TITLE_CONTENT Title;
	} Content;
} XCONTENT_FULL_HEADER, *PXCONTENT_FULL_HEADER; // size 44302
C_ASSERT(sizeof(XCONTENT_FULL_HEADER) == 0xAD0E);

// HASH STUFF
typedef struct _STF_HASH_ENTRY { 
	UCHAR Hash[0x14]; // 0x0 sz:0x14
	//struct <unnamed-tag> Level0; // 0x14 sz:0x4 3 way union!!!
	//struct <unnamed-tag> LevelN; // 0x14 sz:0x4
	DWORD LevelAsULONG; // 0x14 sz:0x4
} STF_HASH_ENTRY, *PSTF_HASH_ENTRY; // size 24
C_ASSERT(sizeof(STF_HASH_ENTRY) == 0x18);

typedef struct _STF_HASH_BLOCK { 
	STF_HASH_ENTRY Entries[0xAA]; // 0x0 sz:0xFF0
	DWORD NumberOfCommittedBlocks; // 0xFF0 sz:0x4
	UCHAR Padding[0xC]; // 0xFF4 sz:0xC
} STF_HASH_BLOCK, *PSTF_HASH_BLOCK; // size 4096
C_ASSERT(sizeof(STF_HASH_BLOCK) == 0x1000);

typedef struct _SVOD_LEVEL0_HASH_BLOCK { 
	SVOD_HASH_ENTRY Entries[0xCC]; // 0x0 sz:0xFF0
	UCHAR Reserved[0x10]; // 0xFF0 sz:0x10
} SVOD_LEVEL0_HASH_BLOCK, *PSVOD_LEVEL0_HASH_BLOCK; // size 4096
C_ASSERT(sizeof(SVOD_LEVEL0_HASH_BLOCK) == 0x1000);

typedef struct _SVOD_LEVEL1_HASH_BLOCK { 
	SVOD_HASH_ENTRY Entries[0xCB]; // 0x0 sz:0xFDC
	SVOD_HASH_ENTRY NextFragmentHashEntry; // 0xFDC sz:0x14
	UCHAR Reserved[0x10]; // 0xFF0 sz:0x10
} SVOD_LEVEL1_HASH_BLOCK, *PSVOD_LEVEL1_HASH_BLOCK; // size 4096
C_ASSERT(sizeof(SVOD_LEVEL1_HASH_BLOCK) == 0x1000);

typedef struct _SVOD_LEVEL0_BACKING_BLOCKS { 
	SVOD_LEVEL0_HASH_BLOCK Level0HashBlock; // 0x0 sz:0x1000
	UCHAR DataBlocks[0xCC000]; // 0x1000 sz:0xCC000
} SVOD_LEVEL0_BACKING_BLOCKS, *PSVOD_LEVEL0_BACKING_BLOCKS; // size 839680
C_ASSERT(sizeof(SVOD_LEVEL0_BACKING_BLOCKS) == 0xCD000);

typedef union _STF_FILE_BOUNDS { 
	DWORD FileSize; // 0x0 sz:0x4
	struct{
		USHORT FirstChildDirectoryIndex; // 0x0 sz:0x2
		USHORT LastChildDirectoryIndex; // 0x2 sz:0x2
	} child;
} STF_FILE_BOUNDS, *PSTF_FILE_BOUNDS; // size 4
C_ASSERT(sizeof(STF_FILE_BOUNDS) == 0x4);

typedef union _STF_TIME_STAMP {
	struct {
		DWORD DoubleSeconds : 5; // 0x0 bfo:0x0
		DWORD Minute : 6; // 0x0 bfo:0x5
		DWORD Hour : 5; // 0x0 bfo:0x11
		DWORD Day : 5; // 0x0 bfo:0x16
		DWORD Month : 4; // 0x0 bfo:0x21
		DWORD Year : 7; // 0x0 bfo:0x25
	} bf;
	DWORD AsULONG; // 0x0 sz:0x4
} STF_TIME_STAMP, *PSTF_TIME_STAMP; // size 4
C_ASSERT(sizeof(STF_TIME_STAMP) == 0x4);

typedef struct _STF_DIRECTORY_ENTRY { 
	UCHAR FileName[0x28]; // 0x0 sz:0x28
	UCHAR FileNameLength : 6; // 0x28 bfo:0x0
	UCHAR Contiguous : 1; // 0x28 bfo:0x6
	UCHAR Directory : 1; // 0x28 bfo:0x7
	UCHAR ValidDataBlocks0; // 0x29 sz:0x1
	UCHAR ValidDataBlocks1; // 0x2A sz:0x1
	UCHAR ValidDataBlocks2; // 0x2B sz:0x1
	UCHAR AllocationBlocks0; // 0x2C sz:0x1
	UCHAR AllocationBlocks1; // 0x2D sz:0x1
	UCHAR AllocationBlocks2; // 0x2E sz:0x1
	UCHAR FirstBlockNumber0; // 0x2F sz:0x1
	UCHAR FirstBlockNumber1; // 0x30 sz:0x1
	UCHAR FirstBlockNumber2; // 0x31 sz:0x1
	USHORT DirectoryIndex; // 0x32 sz:0x2
	union _STF_FILE_BOUNDS FileBounds; // 0x34 sz:0x4
	union _STF_TIME_STAMP CreationTimeStamp; // 0x38 sz:0x4
	union _STF_TIME_STAMP LastWriteTimeStamp; // 0x3C sz:0x4
} STF_DIRECTORY_ENTRY, *PSTF_DIRECTORY_ENTRY; // size 64
C_ASSERT(sizeof(STF_DIRECTORY_ENTRY) == 0x40);

// *********** PACKING ENDS HERE **************//
#pragma pack(pop)
// *********** PACKING ENDS HERE **************//

typedef struct _XCONTENT_MOUNTED_PACKAGE { 
	PVOID pvFsDeviceObject; // 0x0 sz:0x4
	PVOID pvFsBlockCache; // 0x4 sz:0x4
	LIST_ENTRY leMountedPackages; // 0x8 sz:0x8
	DWORD dwFlags; // 0x10 sz:0x4
	HANDLE hPackageFile; // 0x14 sz:0x4
	DWORD dwOpenRefCount; // 0x18 sz:0x4
	RTL_CRITICAL_SECTION csHeaderLock; // 0x1C sz:0x1C
	XCONTENT_HEADER ContentHeader; // 0x38 sz:0x344
	XCONTENT_METADATA ContentMetaData; // 0x37C sz:0x93D6
	PBYTE pbOtherMetaData; // 0x9754 sz:0x4
	DWORD dwOtherMetaDataSize; // 0x9758 sz:0x4
	DWORD DeviceIDLocked; // 0x975C sz:0x4
	char szFsDeviceName[0x40]; // 0x9760 sz:0x40
	char szPackageFilePath[MAX_PATH]; // 0x97A0 sz:0x104
	DWORD dwLicenseMaskLast; // 0x98A4 sz:0x4
	DWORD dwModifiedMetadataOffset; // 0x98A8 sz:0x4
} XCONTENT_MOUNTED_PACKAGE, *PXCONTENT_MOUNTED_PACKAGE; // size 39084
C_ASSERT(sizeof(XCONTENT_MOUNTED_PACKAGE) == 0x98AC);


typedef struct _XCONTENT_DATA_MEDIA { 
	BYTE rgSeriesId[0x10]; // 0x0 sz:0x10
	BYTE rgSeasonId[0x10]; // 0x10 sz:0x10
	WORD wSeasonNumber; // 0x20 sz:0x2
	WORD wEpisodeNumber; // 0x22 sz:0x2
} XCONTENT_DATA_MEDIA, *PXCONTENT_DATA_MEDIA; // size 36
C_ASSERT(sizeof(XCONTENT_DATA_MEDIA) == 0x24);

typedef struct _XCONTENT_DATA_AVATAR_ASSET { 
	DWORD dwSubCategory; // 0x0 sz:0x4
	int fColorizable; // 0x4 sz:0x4
	BYTE rgAssetId[0x10]; // 0x8 sz:0x10
	BYTE SkeletonVersionMask; // 0x18 sz:0x1
} XCONTENT_DATA_AVATAR_ASSET, *PXCONTENT_DATA_AVATAR_ASSET; // size 28
C_ASSERT(sizeof(XCONTENT_DATA_AVATAR_ASSET) == 0x1C);

typedef struct _TYPED_MEDIA_URL { 
	DWORD dwMediaUrlType; // 0x0 sz:0x4
	DWORD dwUrlSize; // 0x4 sz:0x4
	char * pszUrl; // 0x8 sz:0x4
} TYPED_MEDIA_URL, *PTYPED_MEDIA_URL; // size 12
C_ASSERT(sizeof(TYPED_MEDIA_URL) == 0xC);

typedef struct _MEDIA_INSTANCE_URLS { 
	GUID MediaID; // 0x0 sz:0x10
	GUID MediaInstanceID; // 0x10 sz:0x10
	QWORD qwPackageSize; // 0x20 sz:0x8
	QWORD qwInstallSize; // 0x28 sz:0x8
	BYTE rgbSymKey[0x10]; // 0x30 sz:0x10
	BYTE rgbPubKey[0x11C]; // 0x40 sz:0x11C
	DWORD dwPackageType; // 0x15C sz:0x4
	DWORD dwUrlCount; // 0x160 sz:0x4
	PTYPED_MEDIA_URL pUrls; // 0x164 sz:0x4
} MEDIA_INSTANCE_URLS, *PMEDIA_INSTANCE_URLS; // size 360
C_ASSERT(sizeof(MEDIA_INSTANCE_URLS) == 0x168);

typedef struct _FIND_MEDIA_INSTANCE_URLS_RESPONSE { 
	DWORD dwMediaInstanceIdsCount; // 0x0 sz:0x4
	PMEDIA_INSTANCE_URLS pMediaInstanceIds; // 0x4 sz:0x4
} FIND_MEDIA_INSTANCE_URLS_RESPONSE, *PFIND_MEDIA_INSTANCE_URLS_RESPONSE; // size 8
C_ASSERT(sizeof(FIND_MEDIA_INSTANCE_URLS_RESPONSE) == 0x8);

//typedef struct _XCONTENT_DATA { // this is in the sdk already
//	DWORD DeviceID; // 0x0 sz:0x4
//	DWORD dwContentType; // 0x4 sz:0x4
//	wchar_t szDisplayName[0x80]; // 0x8 sz:0x100
//	char szFileName[0x2A]; // 0x108 sz:0x2A
//} XCONTENT_DATA, *PXCONTENT_DATA; // size 308
//C_ASSERT(sizeof(XCONTENT_DATA) == 0x134);

typedef struct _XCONTENT_DATA_INTERNAL {
	XCONTENT_DATA xcData;
	DWORD dwCategory; // 0x134 sz:0x4
	XUID xuid; // 0x138 sz:0x8
	DWORD dwTitleId; // 0x140 sz:0x4
	DWORD dwLicenseMask; // 0x144 sz:0x4
	ULONGLONG ullContentSize; // 0x148 sz:0x8
	FILETIME ftCreationTime; // 0x150 sz:0x8
	wchar_t szTitleName[0x40]; // 0x158 sz:0x80
	union{
		XCONTENT_DATA_MEDIA MediaContentData; // 0x1D8 sz:0x24
		XCONTENT_DATA_AVATAR_ASSET AvatarContentData; // 0x1D8 sz:0x1C
	};
	DWORD fPartial : 1; // 0x1FC bfo:0x0
	DWORD fCorrupt : 1; // 0x1FC bfo:0x1
	DWORD fKinectEnabled : 1; // 0x1FC bfo:0x2
	DWORD fDeepLinkSupported : 1; // 0x1FC bfo:0x3
	DWORD fDisableNetworkStorage : 1; // 0x1FC bfo:0x4
	DWORD fMoveOnlyTransfer : 1; // 0x1FC bfo:0x5
	DWORD fDeviceTransfer : 1; // 0x1FC bfo:0x6
	DWORD fProfileTransfer : 1; // 0x1FC bfo:0x7
	DWORD dwReserved : 24; // 0x1FC bfo:0x8
} XCONTENT_DATA_INTERNAL, *PXCONTENT_DATA_INTERNAL; // size 512
C_ASSERT(sizeof(XCONTENT_DATA_INTERNAL) == 0x200);

typedef struct _BACKGROUND_DOWNLOAD_ITEM { 
	XMARKETPLACE_MEDIA_TYPE MediaType; // 0x0 sz:0x4
	DWORD dwEffectiveTitleId; // 0x4 sz:0x4
	XUID xuid; // 0x8 sz:0x8
	UCHAR consoleId[0x5]; // 0x10 sz:0x5
	UCHAR contentId[0x14]; // 0x15 sz:0x14
	DWORD dwState; // 0x2C sz:0x4
	DWORD dwRatingId; // 0x30 sz:0x4
	GUID mediaId; // 0x34 sz:0x10
	GUID mediaInstanceId; // 0x44 sz:0x10
	GUID offerId; // 0x54 sz:0x10
	wchar_t wszOfferName[0x80]; // 0x64 sz:0x100
	char szPath[0x104]; // 0x164 sz:0x104
	LARGE_INTEGER liInstallSize; // 0x268 sz:0x8
	DWORD dwPercentCompleted; // 0x270 sz:0x4
	int bRepeatDownload; // 0x274 sz:0x4
	char szUrl[0x100]; // 0x278 sz:0x100
	LARGE_INTEGER liDownloadSize; // 0x378 sz:0x8
} BACKGROUND_DOWNLOAD_ITEM, *PBACKGROUND_DOWNLOAD_ITEM; // size 896
C_ASSERT(sizeof(BACKGROUND_DOWNLOAD_ITEM) == 0x380);

#endif // __XAMEXT_XCONTENT_H
