#ifndef VERSION_H
#define VERSION_H

#ifdef IS_ANTICHEAT_VER
	#define PRODUCT_NAME "YR-Spawner (AntiCheat)"
#else
	#define PRODUCT_NAME "YR-Spawner"
#endif

#define FILE_DESCRIPTION "CnCNet5: Spawner"

#define _WSTR(x) _WSTR_(x)
#define _WSTR_(x) L ## #x
#define _STR(x) _STR_(x)
#define _STR_(x) #x

#pragma region Release build version numbering

// Indicates project maturity and completeness
#define VERSION_MAJOR 0

// Indicates major changes and significant additions, like new logics
#define VERSION_MINOR 0

// Indicates minor changes, like vanilla bugfixes, unhardcodings or hacks
#define VERSION_REVISION 0

// Indicates YR-Spawner-related bugfixes only
#define VERSION_PATCH 0

#pragma endregion

// Build number. Incremented on each released build.
#define BUILD_NUMBER 0

// Nightly defines GIT_COMMIT and GIT_BRANCH in GH Actions

#ifdef IS_RELEASE_VER // Release build metadata
	#define FILE_VERSION_STR _STR(VERSION_MAJOR) "." _STR(VERSION_MINOR) "." _STR(VERSION_REVISION) "." _STR(VERSION_PATCH)
	#define FILE_VERSION VERSION_MAJOR, VERSION_MINOR, VERSION_REVISION, VERSION_PATCH
	#define PRODUCT_VERSION "Release Build " FILE_VERSION_STR
#elif defined(GIT_COMMIT) // Nightly devbuild metadata
	#define STR_GIT_COMMIT _STR(GIT_COMMIT)
	#define STR_GIT_BRANCH _STR(GIT_BRANCH)

	#define FILE_VERSION_STR "Commit " STR_GIT_COMMIT
	#define FILE_VERSION 0
	#define PRODUCT_VERSION "Nightly Build " STR_GIT_COMMIT " @ " STR_GIT_BRANCH
#else // Regular devbuild metadata
	#define FILE_VERSION_STR "Build #" _STR(BUILD_NUMBER)
	#define FILE_VERSION 0,0,0,BUILD_NUMBER
	#define PRODUCT_VERSION "Development Build #" _STR(BUILD_NUMBER)
#endif

#endif // VERSION_H
