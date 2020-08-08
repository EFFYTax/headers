#include <sys/cdefs.h>

__BEGIN_DECLS

// Strangely there is no info to find about this function by searching on Google
// Returns the root directory for the iOS simulator
// (example: `/Applications/Xcode-beta.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk`
// or `/` on an actual iOS device
NSString *UISystemRootDirectory();

__END_DECLS
