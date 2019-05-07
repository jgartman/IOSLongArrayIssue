# IOSLongArrayIssue
## Reproduction steps:
After cloning the repo set an environment variable J2OBJC_HOME that points to your local j2objc distribution

![set j2objc home](/screenshots/screenshot4.jpg)

Run the translate.sh script and verify that the files TestClass.m and TestClass.h are generated

![run translate](/screenshots/screenshot3.jpg)

Open the XCode project and set the J2OBJC_HOME variable under user defined build settings to again point to your local j2objc distribution

![set j2objc home in xcode](/screenshots/screenshot1.jpg)

Build and install the test app on an iOS device.  Set a breakpoint in NativeTestClass.cpp and observe that integer and
long_ have different values even though they were the same in the original java code (lines 5-6 of TestClass.java)

![long value is a bit off](/screenshots/screenshot6.jpg)

## Possible root cause:
In jni.m GetPrimitiveArrayCritical casts the array to an IOSByteArray because it assumes that all IOSPrimitiveArray types have
their buffer at the same offset https://github.com/google/j2objc/blob/master/jre_emul/Classes/jni.m#L186

However, setting a breakpoint in the TestClass.m file of the test app it can be seen that IOSIntArray has its buffer offset by
12 bytes from the objects base address while the buffer for IOSLongArray is at 16 bytes

![buffer offset](/screenshots/screenshot7.jpg)

As a result the pointer returned by GetPrimitiveArrayCritical is offset by 4 bytes less than it should be in the case of an
IOSLongArray

![ios long array pointer](/screenshots/screenshot5.jpg)
