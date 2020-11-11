// Objective-C API for talking to github.com/tladesignz/IPtProxy.git Go package.
//   gobind -lang=objc github.com/tladesignz/IPtProxy.git
//
// File is generated by gobind. Do not edit.

#ifndef __IPtProxy_H__
#define __IPtProxy_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"


FOUNDATION_EXPORT const int64_t IPtProxyMeekSocksPort;
FOUNDATION_EXPORT const int64_t IPtProxyObfs2SocksPort;
FOUNDATION_EXPORT const int64_t IPtProxyObfs3SocksPort;
FOUNDATION_EXPORT const int64_t IPtProxyObfs4SocksPort;
FOUNDATION_EXPORT const int64_t IPtProxyScramblesuitSocksPort;
FOUNDATION_EXPORT const int64_t IPtProxySnowflakeSocksPort;

@interface IPtProxy : NSObject
/**
 * Override TOR_PT_STATE_LOCATION, which defaults to "$TMPDIR/pt_state".
 */
+ (NSString* _Nonnull) stateLocation;
+ (void) setStateLocation:(NSString* _Nonnull)v;

@end

/**
 * Start the Obfs4Proxy.

@param logLevel Log level (ERROR/WARN/INFO/DEBUG). Defaults to ERROR if empty string.

@param enableLogging Log to TOR_PT_STATE_LOCATION/obfs4proxy.log.

@param unsafeLogging Disable the address scrubber.
 */
FOUNDATION_EXPORT void IPtProxyStartObfs4Proxy(NSString* _Nullable logLevel, BOOL enableLogging, BOOL unsafeLogging);

/**
 * Start the Snowflake client.

@param ice Comma-separated list of ICE servers.

@param url URL of signaling broker.

@param front Front domain.

@param logFile Name of log file. OPTIONAL

@param logToStateDir Resolve the log file relative to Tor's PT state dir.

@param keepLocalAddresses Keep local LAN address ICE candidates.

@param unsafeLogging Prevent logs from being scrubbed.

@param maxPeers Capacity for number of multiplexed WebRTC peers. DEFAULTs to 1 if less than that.
 */
FOUNDATION_EXPORT void IPtProxyStartSnowflake(NSString* _Nullable ice, NSString* _Nullable url, NSString* _Nullable front, NSString* _Nullable logFile, BOOL logToStateDir, BOOL keepLocalAddresses, BOOL unsafeLogging, long maxPeers);

/**
 * Start the Snowflake proxy.

@param capacity Maximum concurrent clients. OPTIONAL. Defaults to 10, if 0.

@param broker Broker URL. OPTIONAL. Defaults to https://snowflake-broker.bamsoftware.com/, if empty.

@param relay WebSocket relay URL. OPTIONAL. Defaults to wss://snowflake.bamsoftware.com/, if empty.

@param stun STUN URL. OPTIONAL. Defaults to stun:stun.stunprotocol.org:3478, if empty.

@param logFile Name of log file. OPTIONAL

@param keepLocalAddresses Keep local LAN address ICE candidates.

@param unsafeLogging Prevent logs from being scrubbed.
 */
FOUNDATION_EXPORT void IPtProxyStartSnowflakeProxy(long capacity, NSString* _Nullable broker, NSString* _Nullable relay, NSString* _Nullable stun, NSString* _Nullable logFile, BOOL keepLocalAddresses, BOOL unsafeLogging);

/**
 * Stop the Obfs4Proxy.
 */
FOUNDATION_EXPORT void IPtProxyStopObfs4Proxy(void);

#endif
