#include <iostream>
#include <vector>

using namespace std;

vector<double>input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}

void
find_minmax(vector<double> numbers, double& min, double& max)
{
    min = numbers[0];
    max = numbers[0];
    for (double number : numbers)
    {
        if (number < min)
        {
            min = number;
        }
        if (number > max)
        {
            max = number;
        }
    }
}
vector<size_t>make_histogram(const vector<double>& numbers, size_t count, double min, double max)
{
    vector<size_t> bins(count);
    for (double number : numbers)
    {
        size_t bin = (size_t)((number - min) / (max - min) * count);
        if (bin == count)
        {
            bin--;
        }
        bins[bin]++;
    }
    return bins;
}

void show_histogram_text (vector<size_t> bins)
{
    // ????? ??????
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;

    size_t max_count = 0;
    for (size_t count : bins)
    {
        if (count > max_count)
        {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > MAX_ASTERISK;

    for (size_t bin : bins)
    {
        if (bin < 100)
        {
            cout << ' ';
        }
        if (bin < 10)
        {
            cout << ' ';
        }
        cout << bin << "|";

        size_t height = bin;
        if (scaling_needed)
        {
            const double scaling_factor = (double)MAX_ASTERISK / max_count;
            height = (size_t)(bin * scaling_factor);
        }

        for (size_t i = 0; i < height; i++)
        {
            cout << '*';
        }
        cout << '\n';
    }
}
    int main()
    {
        size_t number_count;
        cout << "Enter number count: ";
        cin >> number_count;

        // ???? ????? ??????? ??????? ???????:
        auto const numbers = input_numbers(number_count);

        size_t bin_count;
        cerr << "Enter column count: ";
        cin >> bin_count;
        double min=numbers[0];
        double max=numbers[0];

        find_minmax(numbers, min, max);

        const auto bins = make_histogram(numbers, bin_count, min, max);
        show_histogram_text(bins);


        return 0;
    }
