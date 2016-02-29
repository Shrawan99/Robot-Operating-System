class Encoder{
	private:
	unsigned int dirPin;
	unsigned int intPin;
  	//volatile bool isCheck;
  	
	public:
	volatile int noOfClick;
	Encoder(unsigned int intPin, unsigned int dirPin);
	void increment();
	//void check();
	//bool intReceived();
};
