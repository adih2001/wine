/*
 * HTTPAPI implementation
 *
 * Copyright 2009 Austin English
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include "config.h"

#include <stdarg.h>

#include "windef.h"
#include "winbase.h"
#include "http.h"
#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(httpapi);

BOOL WINAPI DllMain( HINSTANCE hinst, DWORD reason, LPVOID lpv )
{
    switch(reason)
    {
    case DLL_WINE_PREATTACH:
        return FALSE;  /* prefer native version */
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls( hinst );
        break;
    }
    return TRUE;
}

/***********************************************************************
 *        HttpInitialize       (HTTPAPI.@)
 *
 * Initializes HTTP Server API engine
 *
 * PARAMS
 *   version  [ I] HTTP API version which caller will use
 *   flags    [ I] initialization options which specify parts of API what will be used
 *   reserved [IO] reserved, must be NULL
 *
 * RETURNS
 *   NO_ERROR if function succeeds, or error code if function fails
 *
 */
ULONG WINAPI HttpInitialize( HTTPAPI_VERSION version, ULONG flags, PVOID reserved )
{
    FIXME( "({%d,%d}, 0x%x, %p): stub!\n", version.HttpApiMajorVersion,
           version.HttpApiMinorVersion, flags, reserved );
    return NO_ERROR;
}

/***********************************************************************
 *        HttpTerminate       (HTTPAPI.@)
 *
 * Cleans up HTTP Server API engine resources allocated by HttpInitialize
 *
 * PARAMS
 *   flags    [ I] options which specify parts of API what should be released
 *   reserved [IO] reserved, must be NULL
 *
 * RETURNS
 *   NO_ERROR if function succeeds, or error code if function fails
 *
 */
ULONG WINAPI HttpTerminate( ULONG flags, PVOID reserved )
{
    FIXME( "(0x%x, %p): stub!\n", flags, reserved );
    return NO_ERROR;
}

/***********************************************************************
 *        HttpDeleteServiceConfiguration     (HTTPAPI.@)
 *
 * Remove configuration record from HTTP Server API configuration store
 *
 * PARAMS
 *   handle     [I] reserved, must be 0
 *   type       [I] configuration record type
 *   config     [I] buffer which contains configuration record information
 *   length     [I] length of configuration record buffer
 *   overlapped [I] reserved, must be NULL
 *
 * RETURNS
 *   NO_ERROR if function succeeds, or error code if function fails
 *
 */
ULONG WINAPI HttpDeleteServiceConfiguration( HANDLE handle, HTTP_SERVICE_CONFIG_ID type,
                 PVOID config, ULONG length, LPOVERLAPPED overlapped )
{
    FIXME( "(%p, %d, %p, %d, %p): stub!\n", handle, type, config, length, overlapped );
    return NO_ERROR;
}

/***********************************************************************
 *        HttpQueryServiceConfiguration     (HTTPAPI.@)
 *
 * Retrieves configuration records from HTTP Server API configuration store
 *
 * PARAMS
 *   handle     [ I] reserved, must be 0
 *   type       [ I] configuration records type
 *   query      [ I] buffer which contains query data used to retrieve records
 *   query_len  [ I] length of query buffer
 *   buffer     [IO] buffer to store query results
 *   buffer_len [ I] length of output buffer
 *   data_len   [ O] optional pointer to a buffer which receives query result length
 *   overlapped [ I] reserved, must be NULL
 *
 * RETURNS
 *   NO_ERROR if function succeeds, or error code if function fails
 *
 */
ULONG WINAPI HttpQueryServiceConfiguration( HANDLE handle, HTTP_SERVICE_CONFIG_ID type,
                 PVOID query, ULONG query_len, PVOID buffer, ULONG buffer_len,
                 PULONG data_len, LPOVERLAPPED overlapped )
{
    FIXME( "(%p, %d, %p, %d, %p, %d, %p, %p): stub!\n", handle, type, query, query_len,
            buffer, buffer_len, data_len, overlapped );
    return ERROR_FILE_NOT_FOUND;
}

/***********************************************************************
 *        HttpSetServiceConfiguration     (HTTPAPI.@)
 *
 * Add configuration record to HTTP Server API configuration store
 *
 * PARAMS
 *   handle     [I] reserved, must be 0
 *   type       [I] configuration record type
 *   config     [I] buffer which contains configuration record information
 *   length     [I] length of configuration record buffer
 *   overlapped [I] reserved, must be NULL
 *
 * RETURNS
 *   NO_ERROR if function succeeds, or error code if function fails
 *
 */
ULONG WINAPI HttpSetServiceConfiguration( HANDLE handle, HTTP_SERVICE_CONFIG_ID type,
                 PVOID config, ULONG length, LPOVERLAPPED overlapped )
{
    FIXME( "(%p, %d, %p, %d, %p): stub!\n", handle, type, config, length, overlapped );
    return NO_ERROR;
}

/***********************************************************************
 *        HttpCreateHttpHandle     (HTTPAPI.@)
 *
 * Creates a handle to the HTTP request queue
 *
 * PARAMS
 *   handle     [O] handle to request queue
 *   reserved   [I] reserved, must be NULL
 *
 * RETURNS
 *   NO_ERROR if function succeeds, or error code if function fails
 *
 */
ULONG WINAPI HttpCreateHttpHandle( PHANDLE handle, ULONG reserved )
{
    FIXME( "(%p, %d): stub!\n", handle, reserved);
    return ERROR_CALL_NOT_IMPLEMENTED;
}

/***********************************************************************
 *        HttpAddUrl     (HTTPAPI.@)
 */
ULONG WINAPI HttpAddUrl( HANDLE handle, PCWSTR url, PVOID reserved )
{
    FIXME( "(%p, %s, %p): stub!\n", handle, debugstr_w(url), reserved );
    return ERROR_CALL_NOT_IMPLEMENTED;
}

/***********************************************************************
 *        HttpCreateServerSession     (HTTPAPI.@)
 */
ULONG WINAPI HttpCreateServerSession( HTTPAPI_VERSION version, HTTP_SERVER_SESSION_ID *id, ULONG reserved )
{
    FIXME( "({%d,%d}, %p, %d): stub!\n", version.HttpApiMajorVersion, version.HttpApiMinorVersion, id, reserved );

    if(!id || reserved)
        return ERROR_INVALID_PARAMETER;
    if((version.HttpApiMajorVersion != 1 && version.HttpApiMajorVersion != 2)  || version.HttpApiMinorVersion != 0)
        return ERROR_REVISION_MISMATCH;

    *id = 0xabcdefff;

    return NO_ERROR;
}

/***********************************************************************
 *        HttpCloseServerSession     (HTTPAPI.@)
 */
ULONG WINAPI HttpCloseServerSession( HTTP_SERVER_SESSION_ID id )
{
    FIXME( "(%s): stub!\n", wine_dbgstr_longlong(id));
    return ERROR_INVALID_PARAMETER;
}

/***********************************************************************
 *        HttpCreateUrlGroup     (HTTPAPI.@)
 */
ULONG WINAPI HttpCreateUrlGroup( HTTP_SERVER_SESSION_ID id, HTTP_URL_GROUP_ID *urlgroupid, ULONG reserved )
{
    FIXME( "(%s, %p, %d): stub!\n", wine_dbgstr_longlong(id), urlgroupid, reserved );

    *urlgroupid = 0xdeadbeef;

    return NO_ERROR;
}

/***********************************************************************
 *        HttpCloseUrlGroup     (HTTPAPI.@)
 */
ULONG WINAPI HttpCloseUrlGroup( HTTP_URL_GROUP_ID urlgroupid )
{
    FIXME( "(%s): stub!\n", wine_dbgstr_longlong(urlgroupid));
    return NO_ERROR;
}

/***********************************************************************
 *        HttpCreateRequestQueue     (HTTPAPI.@)
 */
ULONG WINAPI HttpCreateRequestQueue( HTTPAPI_VERSION version, PCWSTR name, PSECURITY_ATTRIBUTES security, ULONG flags, PHANDLE request )
{
    FIXME( "({%d,%d}, %s, %p, 0x%x, %p): stub!\n",version.HttpApiMajorVersion,version.HttpApiMinorVersion,debugstr_w(name),security,flags,request ); 

    *request = (HANDLE)0xbeefdead;
    return NO_ERROR;
}

/***********************************************************************
 *        HttpSetUrlGroupProperty     (HTTPAPI.@)
 */
ULONG WINAPI HttpSetUrlGroupProperty( HTTP_URL_GROUP_ID urlgroupid, HTTP_SERVER_PROPERTY property, void *property_info, ULONG property_info_length )
{
    FIXME( "(%s, %d, %p, %d): stub!\n", wine_dbgstr_longlong(urlgroupid), property, property_info, property_info_length );
    return NO_ERROR;
}

/***********************************************************************
 *        HttpAddUrlToUrlGroup     (HTTPAPI.@)
 */
ULONG WINAPI HttpAddUrlToUrlGroup( HTTP_URL_GROUP_ID urlgroupid, PCWSTR name, HTTP_URL_CONTEXT urlcontext, ULONG reserved )
{
    FIXME( "(%s, %s, %s, %d): stub!\n", wine_dbgstr_longlong(urlgroupid), debugstr_w(name), wine_dbgstr_longlong(urlcontext), reserved );
    return NO_ERROR;
}

