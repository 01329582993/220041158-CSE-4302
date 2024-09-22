class Counter
{
private:
    int count;
    int incrementStep;
public:
    Counter()
    {
        count = 0;
        incrementStep = 1;
    }
    void setIncrementStep(int step)
    {
        incrementStep = step;
    }
    int getCount()
    {
        return count;
    }
    void increment()
    {
        count += incrementStep;
    }
    void resetCount()
    {
        count = 0;
    }
};
