/*GRB*

    Gerbera - https://gerbera.io/
    
    config.h - this file is part of Gerbera.
    
    Copyright (C) 2020-2021 Gerbera Contributors
    
    Gerbera is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 2
    as published by the Free Software Foundation.

    Gerbera is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Gerbera.  If not, see <http://www.gnu.org/licenses/>.

    $Id$
*/

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <filesystem>
#include <map>
#include <memory>
#include <vector>
namespace fs = std::filesystem;

// forward declaration
class AutoscanList;
class AutoscanDirectory;
class ClientConfigList;
class ConfigOption;
class Database;
class DirectoryConfigList;
class TranscodingProfileList;

enum config_option_t {
    CFG_SERVER_PORT = 0,
    CFG_SERVER_IP,
    CFG_SERVER_NETWORK_INTERFACE,
    CFG_SERVER_NAME,
    CFG_SERVER_MANUFACTURER,
    CFG_SERVER_MANUFACTURER_URL,
    CFG_SERVER_MODEL_NAME,
    CFG_SERVER_MODEL_DESCRIPTION,
    CFG_SERVER_MODEL_NUMBER,
    CFG_SERVER_MODEL_URL,
    CFG_SERVER_SERIAL_NUMBER,
    CFG_SERVER_PRESENTATION_URL,
    CFG_SERVER_APPEND_PRESENTATION_URL_TO,
    CFG_SERVER_UDN,
    CFG_SERVER_HOME,
    CFG_SERVER_TMPDIR,
    CFG_SERVER_WEBROOT,
    CFG_SERVER_SERVEDIR,
    CFG_SERVER_ALIVE_INTERVAL,
    CFG_SERVER_HIDE_PC_DIRECTORY,
    CFG_SERVER_BOOKMARK_FILE,
    CFG_SERVER_UPNP_TITLE_AND_DESC_STRING_LIMIT,
    CFG_SERVER_UI_ENABLED,
    CFG_SERVER_UI_POLL_INTERVAL,
    CFG_SERVER_UI_POLL_WHEN_IDLE,
    CFG_SERVER_UI_ACCOUNTS_ENABLED,
    CFG_SERVER_UI_ACCOUNT_LIST,
    CFG_SERVER_UI_SESSION_TIMEOUT,
    CFG_SERVER_UI_DEFAULT_ITEMS_PER_PAGE,
    CFG_SERVER_UI_ITEMS_PER_PAGE_DROPDOWN,
    CFG_SERVER_UI_SHOW_TOOLTIPS,
    CFG_SERVER_STORAGE,
    CFG_SERVER_STORAGE_MYSQL,
    CFG_SERVER_STORAGE_SQLITE,
    CFG_SERVER_STORAGE_DRIVER,
    CFG_SERVER_STORAGE_SQLITE_ENABLED,
    CFG_SERVER_STORAGE_SQLITE_DATABASE_FILE,
    CFG_SERVER_STORAGE_SQLITE_SYNCHRONOUS,
    CFG_SERVER_STORAGE_SQLITE_RESTORE,
    CFG_SERVER_STORAGE_SQLITE_BACKUP_ENABLED,
    CFG_SERVER_STORAGE_SQLITE_BACKUP_INTERVAL,
    CFG_SERVER_STORAGE_SQLITE_INIT_SQL_FILE,
    CFG_SERVER_STORAGE_MYSQL_ENABLED,
#ifdef HAVE_MYSQL
    CFG_SERVER_STORAGE_MYSQL_HOST,
    CFG_SERVER_STORAGE_MYSQL_PORT,
    CFG_SERVER_STORAGE_MYSQL_USERNAME,
    CFG_SERVER_STORAGE_MYSQL_SOCKET,
    CFG_SERVER_STORAGE_MYSQL_PASSWORD,
    CFG_SERVER_STORAGE_MYSQL_DATABASE,
    CFG_SERVER_STORAGE_MYSQL_INIT_SQL_FILE,
#endif
#if defined(HAVE_FFMPEG) && defined(HAVE_FFMPEGTHUMBNAILER)
    CFG_SERVER_EXTOPTS_FFMPEGTHUMBNAILER_ENABLED,
    CFG_SERVER_EXTOPTS_FFMPEGTHUMBNAILER_THUMBSIZE,
    CFG_SERVER_EXTOPTS_FFMPEGTHUMBNAILER_SEEK_PERCENTAGE,
    CFG_SERVER_EXTOPTS_FFMPEGTHUMBNAILER_FILMSTRIP_OVERLAY,
    CFG_SERVER_EXTOPTS_FFMPEGTHUMBNAILER_WORKAROUND_BUGS,
    CFG_SERVER_EXTOPTS_FFMPEGTHUMBNAILER_IMAGE_QUALITY,
    CFG_SERVER_EXTOPTS_FFMPEGTHUMBNAILER_CACHE_DIR_ENABLED,
    CFG_SERVER_EXTOPTS_FFMPEGTHUMBNAILER_CACHE_DIR,
#endif
    CFG_SERVER_EXTOPTS_MARK_PLAYED_ITEMS_ENABLED,
    CFG_SERVER_EXTOPTS_MARK_PLAYED_ITEMS_STRING_MODE_PREPEND,
    CFG_SERVER_EXTOPTS_MARK_PLAYED_ITEMS_STRING,
    CFG_SERVER_EXTOPTS_MARK_PLAYED_ITEMS_SUPPRESS_CDS_UPDATES,
    CFG_SERVER_EXTOPTS_MARK_PLAYED_ITEMS_CONTENT_LIST,
#ifdef HAVE_LASTFMLIB
    CFG_SERVER_EXTOPTS_LASTFM_ENABLED,
    CFG_SERVER_EXTOPTS_LASTFM_USERNAME,
    CFG_SERVER_EXTOPTS_LASTFM_PASSWORD,
#endif
    CFG_IMPORT_HIDDEN_FILES,
    CFG_IMPORT_FOLLOW_SYMLINKS,
    CFG_IMPORT_FILESYSTEM_CHARSET,
    CFG_IMPORT_METADATA_CHARSET,
    CFG_IMPORT_PLAYLIST_CHARSET,
#ifdef HAVE_JS
    CFG_IMPORT_SCRIPTING_CHARSET,
    CFG_IMPORT_SCRIPTING_COMMON_SCRIPT,
    CFG_IMPORT_SCRIPTING_CUSTOM_SCRIPT,
    CFG_IMPORT_SCRIPTING_PLAYLIST_SCRIPT,
    CFG_IMPORT_SCRIPTING_PLAYLIST_SCRIPT_LINK_OBJECTS,
    CFG_IMPORT_SCRIPTING_IMPORT_SCRIPT,
    CFG_IMPORT_SCRIPTING_IMPORT_SCRIPT_OPTIONS,
    CFG_IMPORT_SCRIPTING_IMPORT_LAYOUT_AUDIO,
    CFG_IMPORT_SCRIPTING_IMPORT_LAYOUT_VIDEO,
    CFG_IMPORT_SCRIPTING_IMPORT_LAYOUT_IMAGE,
    CFG_IMPORT_SCRIPTING_IMPORT_LAYOUT_TRAILER,
#endif // JS
    CFG_IMPORT_SCRIPTING_VIRTUAL_LAYOUT_TYPE,
    CFG_IMPORT_SCRIPTING_IMPORT_GENRE_MAP,
#ifdef HAVE_MAGIC
    CFG_IMPORT_MAGIC_FILE,
#endif
    CFG_IMPORT_AUTOSCAN_TIMED_LIST,
    CFG_IMPORT_AUTOSCAN_USE_INOTIFY,
#ifdef HAVE_INOTIFY
    CFG_IMPORT_AUTOSCAN_INOTIFY_LIST,
#endif
    CFG_IMPORT_MAPPINGS_IGNORE_UNKNOWN_EXTENSIONS,
    CFG_IMPORT_MAPPINGS_EXTENSION_TO_MIMETYPE_CASE_SENSITIVE,
    CFG_IMPORT_MAPPINGS_EXTENSION_TO_MIMETYPE_LIST,
    CFG_IMPORT_MAPPINGS_MIMETYPE_TO_UPNP_CLASS_LIST,
    CFG_IMPORT_MAPPINGS_MIMETYPE_TO_CONTENTTYPE_LIST,
#ifdef HAVE_LIBEXIF
    CFG_IMPORT_LIBOPTS_EXIF_AUXDATA_TAGS_LIST,
    CFG_IMPORT_LIBOPTS_EXIF_CHARSET,
#endif
#ifdef HAVE_EXIV2
    CFG_IMPORT_LIBOPTS_EXIV2_AUXDATA_TAGS_LIST,
    CFG_IMPORT_LIBOPTS_EXIV2_CHARSET,
#endif
#if defined(HAVE_TAGLIB)
    CFG_IMPORT_LIBOPTS_ID3_AUXDATA_TAGS_LIST,
    CFG_IMPORT_LIBOPTS_ID3_CHARSET,
#endif
    CFG_TRANSCODING_TRANSCODING_ENABLED,
    CFG_TRANSCODING_PROFILE_LIST,
#ifdef HAVE_CURL
    CFG_EXTERNAL_TRANSCODING_CURL_BUFFER_SIZE,
    CFG_EXTERNAL_TRANSCODING_CURL_FILL_SIZE,
#endif //HAVE_CURL
#ifdef SOPCAST
    CFG_ONLINE_CONTENT_SOPCAST_ENABLED,
    CFG_ONLINE_CONTENT_SOPCAST_REFRESH,
    CFG_ONLINE_CONTENT_SOPCAST_UPDATE_AT_START,
    CFG_ONLINE_CONTENT_SOPCAST_PURGE_AFTER,
#endif
#ifdef ATRAILERS
    CFG_ONLINE_CONTENT_ATRAILERS_ENABLED,
    CFG_ONLINE_CONTENT_ATRAILERS_REFRESH,
    CFG_ONLINE_CONTENT_ATRAILERS_UPDATE_AT_START,
    CFG_ONLINE_CONTENT_ATRAILERS_PURGE_AFTER,
    CFG_ONLINE_CONTENT_ATRAILERS_RESOLUTION,
#endif
#if defined(HAVE_FFMPEG)
    CFG_IMPORT_LIBOPTS_FFMPEG_AUXDATA_TAGS_LIST,
    CFG_IMPORT_LIBOPTS_FFMPEG_CHARSET,
#endif
    CFG_CLIENTS_LIST,
    CFG_CLIENTS_LIST_ENABLED,
    CFG_IMPORT_LAYOUT_PARENT_PATH,
    CFG_IMPORT_LAYOUT_MAPPING,
    CFG_IMPORT_LIBOPTS_ENTRY_SEP,
    CFG_IMPORT_LIBOPTS_ENTRY_LEGACY_SEP,
    CFG_IMPORT_DIRECTORIES_LIST,
    CFG_IMPORT_RESOURCES_CASE_SENSITIVE,
    CFG_IMPORT_RESOURCES_FANART_FILE_LIST,
    CFG_IMPORT_RESOURCES_SUBTITLE_FILE_LIST,
    CFG_IMPORT_RESOURCES_RESOURCE_FILE_LIST,
    CFG_IMPORT_RESOURCES_CONTAINERART_FILE_LIST,
    CFG_IMPORT_RESOURCES_CONTAINERART_LOCATION,
    CFG_IMPORT_RESOURCES_CONTAINERART_PARENTCOUNT,
    CFG_IMPORT_RESOURCES_CONTAINERART_MINDEPTH,
    CFG_TRANSCODING_MIMETYPE_PROF_MAP_ALLOW_UNUSED,
    CFG_TRANSCODING_PROFILES_PROFILE_ALLOW_UNUSED,
    CFG_VIRTUAL_URL,
    CFG_IMPORT_SYSTEM_DIRECTORIES,
    CFG_UPNP_ALBUM_PROPERTIES,
    CFG_UPNP_ARTIST_PROPERTIES,
    CFG_UPNP_TITLE_PROPERTIES,
    CFG_THREAD_SCOPE_SYSTEM,
    CFG_IMPORT_READABLE_NAMES,

    CFG_MAX,

    // only attributes are allowed beyond CFG_MAX
    ATTR_SERVER_EXTOPTS_MARK_PLAYED_ITEMS_CONTENT,
    ATTR_SERVER_UI_ITEMS_PER_PAGE_DROPDOWN_OPTION,
    ATTR_SERVER_UI_ACCOUNT_LIST_ACCOUNT,
    ATTR_SERVER_UI_ACCOUNT_LIST_USER,
    ATTR_SERVER_UI_ACCOUNT_LIST_PASSWORD,
    ATTR_IMPORT_MAPPINGS_MIMETYPE_MAP,
    ATTR_IMPORT_MAPPINGS_MIMETYPE_FROM,
    ATTR_IMPORT_MAPPINGS_MIMETYPE_TO,
    ATTR_IMPORT_MAPPINGS_M2CTYPE_LIST_TREAT,
    ATTR_IMPORT_MAPPINGS_M2CTYPE_LIST_MIMETYPE,
    ATTR_IMPORT_MAPPINGS_M2CTYPE_LIST_AS,
    ATTR_IMPORT_LAYOUT_GENRE,
    ATTR_IMPORT_LAYOUT_SCRIPT_OPTION,
    ATTR_IMPORT_LAYOUT_SCRIPT_OPTION_NAME,
    ATTR_IMPORT_LAYOUT_SCRIPT_OPTION_VALUE,
    ATTR_IMPORT_LAYOUT_MAPPING_PATH,
    ATTR_IMPORT_LAYOUT_MAPPING_FROM,
    ATTR_IMPORT_LAYOUT_MAPPING_TO,
    ATTR_IMPORT_RESOURCES_ADD_FILE,
    ATTR_IMPORT_RESOURCES_NAME,
    ATTR_IMPORT_LIBOPTS_AUXDATA_DATA,
    ATTR_IMPORT_LIBOPTS_AUXDATA_TAG,
    ATTR_TRANSCODING_MIMETYPE_PROF_MAP,
    ATTR_TRANSCODING_MIMETYPE_PROF_MAP_TRANSCODE,
    ATTR_TRANSCODING_MIMETYPE_PROF_MAP_MIMETYPE,
    ATTR_TRANSCODING_MIMETYPE_PROF_MAP_USING,
    ATTR_TRANSCODING_PROFILES_PROFLE,
    ATTR_TRANSCODING_PROFILES_PROFLE_ENABLED,
    ATTR_TRANSCODING_PROFILES_PROFLE_TYPE,
    ATTR_TRANSCODING_PROFILES_PROFLE_NAME,
    ATTR_TRANSCODING_PROFILES_PROFLE_MIMETYPE,
    ATTR_TRANSCODING_PROFILES_PROFLE_RES,
    ATTR_TRANSCODING_PROFILES_PROFLE_AVI4CC,
    ATTR_TRANSCODING_PROFILES_PROFLE_AVI4CC_MODE,
    ATTR_TRANSCODING_PROFILES_PROFLE_AVI4CC_4CC,
    ATTR_TRANSCODING_PROFILES_PROFLE_ACCURL,
    ATTR_TRANSCODING_PROFILES_PROFLE_SAMPFREQ,
    ATTR_TRANSCODING_PROFILES_PROFLE_NRCHAN,
    ATTR_TRANSCODING_PROFILES_PROFLE_HIDEORIG,
    ATTR_TRANSCODING_PROFILES_PROFLE_THUMB,
    ATTR_TRANSCODING_PROFILES_PROFLE_FIRST,
    ATTR_TRANSCODING_PROFILES_PROFLE_ACCOGG,
    ATTR_TRANSCODING_PROFILES_PROFLE_AGENT,
    ATTR_TRANSCODING_PROFILES_PROFLE_AGENT_COMMAND,
    ATTR_TRANSCODING_PROFILES_PROFLE_AGENT_ARGS,
    ATTR_TRANSCODING_PROFILES_PROFLE_BUFFER,
    ATTR_TRANSCODING_PROFILES_PROFLE_BUFFER_SIZE,
    ATTR_TRANSCODING_PROFILES_PROFLE_BUFFER_CHUNK,
    ATTR_TRANSCODING_PROFILES_PROFLE_BUFFER_FILL,
    ATTR_AUTOSCAN_DIRECTORY,
    ATTR_AUTOSCAN_DIRECTORY_LOCATION,
    ATTR_AUTOSCAN_DIRECTORY_MODE,
    ATTR_AUTOSCAN_DIRECTORY_INTERVAL,
    ATTR_AUTOSCAN_DIRECTORY_RECURSIVE,
    ATTR_AUTOSCAN_DIRECTORY_HIDDENFILES,
    ATTR_AUTOSCAN_DIRECTORY_SCANCOUNT,
    ATTR_AUTOSCAN_DIRECTORY_TASKCOUNT,
    ATTR_AUTOSCAN_DIRECTORY_LMT,
    ATTR_CLIENTS_CLIENT,
    ATTR_CLIENTS_CLIENT_FLAGS,
    ATTR_CLIENTS_CLIENT_IP,
    ATTR_CLIENTS_CLIENT_USERAGENT,
    ATTR_DIRECTORIES_TWEAK,
    ATTR_DIRECTORIES_TWEAK_LOCATION,
    ATTR_DIRECTORIES_TWEAK_INHERIT,
    ATTR_DIRECTORIES_TWEAK_RECURSIVE,
    ATTR_DIRECTORIES_TWEAK_HIDDEN,
    ATTR_DIRECTORIES_TWEAK_CASE_SENSITIVE,
    ATTR_DIRECTORIES_TWEAK_FOLLOW_SYMLINKS,
    ATTR_DIRECTORIES_TWEAK_META_CHARSET,
    ATTR_DIRECTORIES_TWEAK_FANART_FILE,
    ATTR_DIRECTORIES_TWEAK_SUBTILTE_FILE,
    ATTR_DIRECTORIES_TWEAK_RESOURCE_FILE,
    ATTR_IMPORT_SYSTEM_DIR_ADD_PATH,
    ATTR_UPNP_PROPERTIES_PROPERTY,
    ATTR_UPNP_PROPERTIES_UPNPTAG,
    ATTR_UPNP_PROPERTIES_METADATA,
};

class Config {
public:
    virtual ~Config() = default;
    virtual void updateConfigFromDatabase(std::shared_ptr<Database> database) = 0;
    virtual std::string getOrigValue(const std::string& item) const = 0;
    virtual void setOrigValue(const std::string& item, const std::string& value) = 0;
    virtual void setOrigValue(const std::string& item, bool value) = 0;
    virtual void setOrigValue(const std::string& item, int value) = 0;
    virtual bool hasOrigValue(const std::string& item) const = 0;

    /// \brief Returns the path of the config file that was used to launch the server.
    virtual fs::path getConfigFilename() const = 0;

    /// \brief Returns the path of the directory holding gerbera data files (sql,web,js)
    virtual fs::path getDataDir() const = 0;

    /// \brief add a config option
    /// \param option option type to add.
    /// \param option option to add.
    virtual void addOption(config_option_t option, std::shared_ptr<ConfigOption> optionValue) = 0;

    /// \brief returns a config option of type std::string
    /// \param option option to retrieve.
    virtual std::string getOption(config_option_t option) const = 0;

    /// \brief returns a config option of type int
    /// \param option option to retrieve.
    virtual int getIntOption(config_option_t option) const = 0;

    /// \brief returns a config option of type bool
    /// \param option option to retrieve.
    virtual bool getBoolOption(config_option_t option) const = 0;

    /// \brief returns a config option of type dictionary
    /// \param option option to retrieve.
    virtual std::map<std::string, std::string> getDictionaryOption(config_option_t option) const = 0;

    /// \brief returns a config option of type array of string
    /// \param option option to retrieve.
    virtual std::vector<std::string> getArrayOption(config_option_t option) const = 0;

    /// \brief returns a config option of type AutoscanList
    /// \param option to retrieve
    virtual std::shared_ptr<AutoscanList> getAutoscanListOption(config_option_t option) const = 0;

    /// \brief returns a config option of type ClientConfigList
    /// \param option to retrieve
    virtual std::shared_ptr<ClientConfigList> getClientConfigListOption(config_option_t option) const = 0;

    /// \brief returns a config option of type DirectoryConfigList
    /// \param option to retrieve
    virtual std::shared_ptr<DirectoryConfigList> getDirectoryTweakOption(config_option_t option) const = 0;

    /// \brief returns a config option of type TranscodingProfileList
    /// \param option to retrieve
    virtual std::shared_ptr<TranscodingProfileList> getTranscodingProfileListOption(config_option_t option) const = 0;
};

#endif // __CONFIG_H__
