/*
Mo's algorithm is a prperty of sorting

We sort queries int the manner o that usin two pointer we can find range sum in sqrt(n) time.

Mo's alorithm solve every query in O(sqrt(n)) time.

All queries are known beforehead so that they can be preprocessed

It cannot work for problems where we have update operations also mixed with sum queries.

MO’s algorithm can only be used for query problems where a query can be computed from results of the previous query. One more such example is maximum or minimum.

The preprocessing part takes O(m Log m) time.
Then time complexity of m queruis O(m * √n)