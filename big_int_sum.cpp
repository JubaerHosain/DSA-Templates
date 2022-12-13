string add(string number1, string number2)
{
    if (number1.length() > number2.length())
        swap(number1, number2);

    string sum = "";
    int len1 = number1.length();
    int len2 = number2.length();
    int digitDiff = len2 - len1, carry = 0, intSum;

    for (int i = len1 - 1; i >= 0; i--)
    {
        intSum = ((number1[i] - '0') + (number2[i + digitDiff] - '0') + carry);
        sum.push_back(intSum % 10 + '0');
        carry = intSum / 10;
    }

    for (int i = digitDiff - 1; i >= 0; i--)
    {
        intSum = ((number2[i] - '0') + carry);
        sum.push_back(intSum % 10 + '0');
        carry = intSum / 10;
    }

    if (carry)
        sum.push_back(carry + '0');

    reverse(sum.begin(), sum.end());

    return sum;
}


