void Algorithm_1()
{
    clock_t start, end;
    double time_run;
    inputData inputString;
    cin >> inputString.mode >> inputString.algorithm_name >> inputString.size >> inputString.output_para;
    if (inputString.mode == "-c")
        return 0;
    else
    {
        cout << "ALGORITHM MODE \n";
        cout << "Algorithm: " << inputString.algorithm_name << "\n";
        cout << "Input size: " << inputString.size << "\n";

        int* arr = new int[inputString.size];
        for (int i = 0; i < inputString.size; i++)
        {
            *(arr + i) = rand() % (10000 - 3 + 1) + 3;
        }
        start = clock();
        cout << "Before sort: ";
        for (int i = 0; i < inputString.size; i++)
        {
            cout << "[" << *(arr + i) << "] ";
        }
        cout << "\n";
        quickSort(arr, 0, inputString.size - 1);
        cout << "After sort: ";
        for (int i = 0; i < inputString.size; i++)
        {
            cout << "[" << *(arr + i) << "] ";
        }
        cout << "\n";
        end = clock();
        time_run = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "-------------------------------------\n";
        cout << "Running Time (if required): " << time_run << "\n";
        cout << "Comparison (if required): \n";
        return 0;
    }
}
/*cái ở trên chỉ là prototype*/