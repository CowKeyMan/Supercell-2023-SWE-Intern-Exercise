Decisions Taken and Alternatives
================================

This page will describe the decisions taken while developing the solutions and possible alternatives if they prove to be problematic later on in production.

Task 1
++++++

* The Observer was created as a static member of User. This decision was made so that not every user needs their own reference to the observer, which saves memory and will also lead to less cache misses, since we only need to keep a single observer in memory. Furthermore, if we used shared pointers for every user, given millions of users this would be extremely expensive. In general, code cleanliness wise it might not have made a very big difference, as the UserMap could have easily given a reference of the Observer to the User class.
* The *broadcast*, *timestamp* and *user* keys of the json are only added at the end of the `update_values_notify` function in the `User` class. This is for efficiency, since we do not need to add these to the json if we end up not broadcasting anything in the first place.
* The 'friends' vector of the Users is an ordered map. This data structure was chosen because adding and removing friends is not a common operation, and a user will probably not have millions of friends, hence why we might not need an unordered map. The benefits of this data structure are, however, because we will not need to sort the Users after we send sent them over the network when we broadcast. As an example, when we want to display a User's friends, more than likely we will want to show them as a sorted list. By using this data structure, the values will already be sorted, hence it could be more efficient.

   * Note: this also seemed to be a requirement of the problem statement, since the given output has the friends as a list in the output json, which is understandable since the standard json does not support sets.
   * On the contrary, for the UserMap, an unordered_map was used, since these did not need to be ordered, and we will want to search for users very fast at a high rate (unordered map is constant time for lookup). This `small study <http://supercomputingblog.com/windows/ordered-map-vs-unordered-map-a-performance-study/>`_ shows the performance performance differences between (ordered) map and unordered map.
   * The same logic as above applies when the decision was taken to use unordered map for the user values. However, if we need to often sort the inventory values, it may be a good idea to use the sorted map version instead.

* Error checking in the program is minimal. This was mostly done for simplicity, to keep the code base simple and fast to read through. I am mentioning this point because in a real world scenario, error checking would be done extensively, especially since we are dealing with JSON, which is unstructured. A JSON formatting check would have to be done to make sure it complies with the requirements.

* Empty values are allowed to be accepted and broadcasted. This is because an empty value means that it the item has been unequiped.

* Unchanged values are allowed to be broadcasted if the timestamp is greater, as this was part of the provided tests. In my opinion this should be different.

Task 2
++++++

* The parallel method chosen might not be optimal for batch data as we have here. While fast, another method might be better, where each thread or process processes an equal amount of the file, then the results are merged at the end or periodically, by having each thread broadcast the result of values which have been changed. This would make it parallisable across different processes (not just threads), which means that different machines using different main memory can process the results (ex: across different servers). Another advantage of this method is that we do not need a lock for each User, hence different processes will not need to wait for each other to update the user values and we save memory as well.

    * That said, my method should be optimal for real time / online processing, as we are still using each thread constantly and the User data is being updated immediately after the request is finished processing. We also do not need to do any transferring of data between the threads. A disadvantage, however, as mentioned, is that each user needs their own lock, for updating the values, so that we do not have any race conditions for this. This waiting time would most likely not be such a big issue in a real world scenario since it is unlikely for a user to change their inventory thousands of times a second, unless there is some DoS attack on the servers.

Benchmark
+++++++++

* For the FileLineIterator, inheritance was used. This causes virtual calls, which may be undesirable in a real-world scenario where performance is of utmost importance. Using templates and the CRTP (Curiously Recurring Template Pattern) may instead be more desireable. I chose to use inheritance in this case for the sake of simplicity and because CRTP is in general quite an ugly design pattern in terms of code cleanliness.
