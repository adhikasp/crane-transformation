namespace CraneTranformation
{

	public class Point
	{

	private:	
		int coords[];

	public:

		Point(int x,int y)
		{
			coords[0] = x;
			coords[1] = y;
		}

		int get_x()
		{
			return coords[0];
		
		}

		int get_y()
		{
			return coords[1];
		}

	};
}