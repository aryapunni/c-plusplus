import math


def power_sum(input):
    result = 0
    for x in input:
        if(isinstance(x, int)):
            print("Integer value: ", x)
            
            result = result + x
        else:
            print("size of the list: ", len((x)))
            result = result + power_sum(x) ** len(x)
        print("------result--------:  ", result)
    return result


if __name__ == "__main__":

    input_1 = [2, 3, [4, 1, 2]]
    input_2 = [1, 2, [7, [3, 4], 2]]
    result = power_sum(input_2)
    print(result)