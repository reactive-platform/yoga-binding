using System;
using System.Runtime.InteropServices;

namespace YogaBinding
{
    public delegate void YogaLoggerDelegate(string message, YogaLogLevel level);

    public enum YogaLogLevel
    {
        Error,
        Warn,
        Info,
        Debug,
        Verbose,
        Fatal
    }

    public static class YogaBindings
    {
        private const string DllName = "yoga";

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate void NativeLoggerDelegate(IntPtr message, int logLevel);

        private static YogaLoggerDelegate? _logger;
        private static NativeLoggerDelegate? _nativeLogger;

        public static void SetLogger(YogaLoggerDelegate logger)
        {
            _logger = logger;
            _nativeLogger = (message, logLevel) =>
            {
                if (_logger != null)
                {
                    var messageStr = Marshal.PtrToStringAnsi(message) ?? string.Empty;
                    _logger(messageStr, (YogaLogLevel)logLevel);
                }
            };

            YGBindingsSetLogger(_nativeLogger);
        }

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        private static extern void YGBindingsSetLogger(NativeLoggerDelegate callback);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void YGNodeInsertChildSafe(IntPtr node, IntPtr child, int index);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void YGNodeRemoveChildSafe(IntPtr node, IntPtr child);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void YGNodeRemoveAllChildrenSafe(IntPtr node);
    }
} 