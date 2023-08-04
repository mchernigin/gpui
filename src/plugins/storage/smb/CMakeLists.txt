find_package(GPUI COMPONENTS io model REQUIRED)
include_directories(${GPUI_INCLUDE_DIRS})

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(PLUGIN_NAME smb-storage-plugin)
set(PLUGIN_LIBRARY_NAME smb-storage-static)

set(HEADERS
    smbclient.h
    smbdirectory.h
    smbfile.h
    smbauthenticationdialog.h
)

set(SOURCES
    smbclient.cpp
    smbdirectory.cpp
    smbfile.cpp
    smbstorageplugin.cpp
    smbauthenticationdialog.cpp
)

set(UI_FORMS
    smbauthenticationdialog.ui
)

set(SOURCES ${SOURCES} ${HEADERS} ${UI_FORMS})

add_gpui_plugin(${PLUGIN_NAME} ${SOURCES})
target_link_libraries(${PLUGIN_NAME} Qt5::Core Qt5::Widgets)

add_library(${PLUGIN_LIBRARY_NAME} STATIC ${SOURCES})
target_link_libraries(${PLUGIN_LIBRARY_NAME} Qt5::Core Qt5::Widgets)

## samba requires libsmbclient
find_path(SAMBA_INCLUDE_DIR
          NAMES libsmbclient.h
          HINTS /usr/include/smbclient
                /usr/include/samba
                /usr/include/samba-3.0
                /usr/include/samba-4.0
          )
find_library(SAMBA_LIBRARIES NAMES smbclient )
message(STATUS "samba include=${SAMBA_INCLUDE_DIR}")
message(STATUS "samba lib=${SAMBA_LIBRARIES}=${SAMBA_LIBRARIES}")

if(SAMBA_INCLUDE_DIR AND SAMBA_LIBRARIES)
   message(STATUS "Found samba: include=${SAMBA_INCLUDE_DIR}  library=${SAMBA_LIBRARIES}")
   include_directories(${SAMBA_INCLUDE_DIR})

   target_link_libraries(${PLUGIN_NAME} ${SAMBA_LIBRARIES})
   target_link_libraries(${PLUGIN_LIBRARY_NAME} ${SAMBA_LIBRARIES})
else(SAMBA_INCLUDE_DIR AND SAMBA_LIBRARIES)
   message(FATAL_ERROR "Could not find Samba libsmbclient")
endif(SAMBA_INCLUDE_DIR AND SAMBA_LIBRARIES)
mark_as_advanced(SAMBA_INCLUDE_DIR SAMBA_LIBRARIES)
## end samba confiuration
