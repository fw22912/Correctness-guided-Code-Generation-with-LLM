int maxNumberOfBalloons(char *text)
{
    
    int count_letters[5] = {0};
    int i, min_counter_ballons;

    for (char *ptr = text; *ptr; ptr++)
    {
        if (*ptr == 'b')
        {
            count_letters[0]++;
        }
        else if (*ptr == 'a')
        {
            count_letters[1]++;
        }
        else if (*ptr == 'l')
        {
            count_letters[2]++;
        }
        else if (*ptr == 'o')
        {
            count_letters[3]++;
        }
        else if (*ptr == 'n')
        {
            count_letters[4]++;
        }
    }

    
    count_letters[2] /= 2;
    count_letters[3] /= 2;

    
    min_counter_ballons = count_letters[0];
    for (i = 1; i < 5; i++)
    {
        if (count_letters[i] < min_counter_ballons)
            min_counter_ballons = count_letters[i];
    }

    return min_counter_ballons;
}
