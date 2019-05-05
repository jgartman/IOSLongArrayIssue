#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    void Java_TestClass_nativeTestFunc(JNIEnv *_env_, jclass _cls_, jarray intArray, jarray longArray){
        jboolean intArrayIsCopy;
        jint* intArrayPtr = (jint*)_env_->GetPrimitiveArrayCritical(intArray,&intArrayIsCopy);
        jboolean longArrayIsCopy;
        jlong* longArrayPtr = (jlong*)_env_->GetPrimitiveArrayCritical(longArray, &longArrayIsCopy);
        
        int integer = intArrayPtr[0];
        long long_ = longArrayPtr[0];
    }
    
#ifdef __cplusplus
}
#endif
