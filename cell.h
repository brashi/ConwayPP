class Cell {
	private:
		bool state;
		int xCoord;
		int yCoord;
		
	public:
		Cell();
		Cell(int x, int y);
		void setState(bool st);
		bool getState();

};

