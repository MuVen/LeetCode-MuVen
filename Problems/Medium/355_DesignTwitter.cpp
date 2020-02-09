/*
Design a simplified version of Twitter where users can post tweets, 
follow/unfollow another user and is able to see the 10 most recent tweets in 
the user's news feed. Your design should support the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news 
feed. Each item in the news feed must be posted by users who the user followed 
or by the user herself. Tweets must be ordered from most recent to least recent.
follow(followerId, followeeId): Follower follows a followee.
unfollow(followerId, followeeId): Follower unfollows a followee.
Example:

Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
*/

//solution
struct idlink{
	int id;
	int counter;
	idlink* next;
	idlink* prev;
};
idlink idlinknodes[1000];

struct idlinkfl{
	idlink* first;
	idlink* last;
};

class Twitter {
	unordered_map<int, vector<pair<int, int>>> map;
	unordered_map<int, vector<int>> ufollow;
	vector<int> result;
	idlinkfl mpfl;
	int pindex;
	int twitterCounter;
public:
	/** Initialize your data structure here. */
	Twitter() {
		map.clear();
		twitterCounter = 1;
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		map[userId].push_back({ tweetId, twitterCounter++ });
	}

	idlink* getIDNode(int id, int counter){
		idlink* temp = &idlinknodes[pindex++];
		temp->id = id;
		temp->counter = counter;
		temp->next = temp->prev = nullptr;
		return temp;
	}

	void initNewsFeed(){
		result.clear();
		pindex = 0;
		mpfl.first = mpfl.last = nullptr;
	}
	
	void insertionSort(int id, int tcounter){
		if (mpfl.first == nullptr && mpfl.last == nullptr){
			mpfl.first = mpfl.last = getIDNode(id, tcounter);
			return;
		}

		idlink* temp = mpfl.first;
		idlink* mptemp = getIDNode(id, tcounter);
		int count = 0;
		while (temp){
			if (mptemp->counter > temp->counter){
				if (temp == mpfl.first){
					temp->prev = mptemp;
					mptemp->next = temp;
					mpfl.first = mptemp;
				}
				else {
					temp->prev->next = mptemp;
					mptemp->prev = temp->prev;
					mptemp->next = temp;
					temp->prev = mptemp;
				}
				return;
			}
			temp = temp->next;
			count++;
			if (count == 10)
				break;
		}

		if (count < 10 && temp == nullptr){
			mpfl.last->next = mptemp;
			mptemp->prev = mpfl.last;
			mpfl.last = mptemp;
		}
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		initNewsFeed();
		{
			auto tweets = map[userId];
			for (int i = 0; i < tweets.size(); i++){
				//cout << userId << " " << tweets[i]<<endl;
				insertionSort(tweets[i].first, tweets[i].second);
			}
		}

		if (map.find(userId) != map.end()){
			auto vec = ufollow[userId];
			for (int i = 0; i < vec.size(); i++){
				int follwingUId = vec[i];
				if (map.find(follwingUId) != map.end()){
					auto tweets = map[follwingUId];
					for (int i = 0; i < tweets.size(); i++){
						//cout << follwingUId << " " << tweets[i] << endl;
						insertionSort(tweets[i].first, tweets[i].second);
					}
				}
			}
		}

		idlink* temp = mpfl.first;
		while (temp){
			result.push_back(temp->id);
			if (result.size() == 10)
				break;
			temp = temp->next;
		}
		return move(result);
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		if (followerId == followeeId)
			return;

		auto &vec = ufollow[followerId];
		auto it = find(vec.begin(), vec.end(), followeeId);
		if (it == vec.end())
			ufollow[followerId].push_back(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (followerId == followeeId)
			return;

		auto& vec = ufollow[followerId];
		auto it = find(vec.begin(), vec.end(), followeeId);
		if (it != vec.end())
			vec.erase(it);
	}
};