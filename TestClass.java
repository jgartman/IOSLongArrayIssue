
class TestClass{

	public void testFunc(){
		int [] intArray = {1234};
		long [] longArray = {1234L};

		nativeTestFunc(intArray, longArray);
	}

	private static native void nativeTestFunc(int [] intArray, long[] longArray);

}

