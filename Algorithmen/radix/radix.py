from more_itertools import flatten


def radix(to_sort: list, max_num_len: int = 3):
    for j in range(1, max_num_len + 1):
        buckets = {str(i): [] for i in range(10)}

        for element in to_sort:
            buckets[str(element)[-j]].append(element)

        sorted_list = list(flatten(buckets.values()))

    return sorted_list


mylist = [123, 832, 512, 672, 897, 345]
print(radix(mylist))
