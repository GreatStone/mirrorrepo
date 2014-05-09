class ColorfulBoxesAndBalls{
public:
  int getMaximum (int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors)
  {
    int res;
    if (onlyRed + onlyBlue > bothColors)
      {
	res = onlyRed * numRed + onlyBlue * numBlue;
      }
    else
      {
	if (numRed > numBlue)
	  {
	    res = numBlue*bothColors + (numRed - numBlue)*onlyBlue;
	  }
	else 
	  {
	    res = numRed*bothColors+(numBlue-numRed)*onlyRed;
	  }
      }
    return res;
  }
};
