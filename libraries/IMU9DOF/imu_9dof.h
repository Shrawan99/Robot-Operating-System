class IMU{
	public:
	IMU();
	void accelInit();
	void gyroInit();
	void magnetomInit();
	void begin();
	int* accelRead();
	int* gyroRead();
	int* magnetomRead();
	
	private:
	int accel[3];
	int gyro[3];
	int magnetom[3];
	
	
};

//extern IMU imu;
