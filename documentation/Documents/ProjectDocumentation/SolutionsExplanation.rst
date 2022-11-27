Solutions Explanation
=====================

Here I will discuss the main components of the system at a high level and how they connect to one another. The below diagram will help visualise the system while reading the explanation.

Solution Diagram
++++++++++++++++

.. _ClassDiagram:
.. mermaid:: graphs/ClassDiagram.mmd

General
+++++++

#. The project starts at the main, which is located in `src/task1.cpp`. This module initialises all the components and feeds one into the other
#. The FileLineIterator takes a filename as input and then serves it line by line.
#. The UserMap is a class which contains an ordered map of the Users. This map maps names to their respective Users. When a user is accessed but not found, it is instead created on the fly.
#. The User is the data subject and stores the values.

   * Each value has a timestamp and the actual string.

#. The UserUpdateObserver observes the user when it updates a value, so that it may broadcast the change to their friends.
#. The TaskHandler is where the work happens. Here, the json string given by the FileLineIterator is parsed, and the tasks (*make_friends, del_friends* or *update*) are executed.

Now I will describe task specific differences.

Task 1
++++++

For this task, the :ref:`General` overview describes this task quite well, as there is not much special handling in the components.

Task 2
++++++

* For this task, the same FileLineIterator is used, but the handler is changed. This time, the UpdateTaskHandler is used since we only need to update the values. This avoids checking which function we need to apply.
* When updating the User value, a mutex lock as added so that we cannot be editing the same user's values at the same time
* Furthermore, a critical section is added to the UserMap class when checking if a user exists and when we need to add them.
* Another critical section is added for reading the file in the FileLineIterator so that `getline()` is not called by 2 threads at the same time.
* Lastly, to parallelise, multiple UpdateTaskHandlers are created so that they all read from the same FileLineIterator and they all update the same UserMap. This is shown in `src/task2.cpp`

Benchmark
+++++++++

* To benchmark the code, I used a different LineFileIterator called *ReadAllLineFileIterator*. This class reads the entire file first and stores it into a string vector, then serves it to the consumers as usual, so the consumers are abstracted from how the actual reading is done.

  * The reason for this decision is so that the benchmarking is independent of any IO, since this could vary depending on wether we are reading from a file or wether we are reading from the network. The physical device will also make this benhmarking difficule (ex: reading from SSD is much faster than reading from a hard drive). Thus, this will allow us to benchmark the scalability of the compute itself.

Benchmarking results
--------------------

The following is an average scaling of 5 runs on my laptop, plugged in on balanced performance mode. The CPU is an *Intel(R) Core(TM) i7-10870H CPU @ 2.20GHz*.

.. plot:: Documents/ProjectDocumentation/graphs/plot_benchmark_results.py

* The best score is 378ms at 15 threads, which leads to a bit less than 3 million requests per second. On high performance mode, this value consistently goes down to under 200ms, which would allow my laptop to handle more than 5 million requests per second, assuming IO is not a bottleneck.

* The next section will describe alternative methods of parallelising this task.
