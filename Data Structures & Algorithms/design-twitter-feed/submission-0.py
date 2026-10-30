class Twitter:
    def __init__(self):
        self.timestamp = 0
        self.tweets = defaultdict(list)
        self.followers = defaultdict(set)

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweets[userId].append((self.timestamp, tweetId))
        self.timestamp += 1

    def getNewsFeed(self, userId: int) -> List[int]:
        heap = self.tweets[userId][:]
        heapq.heapify(heap)
        for followee in self.followers[userId]:            
                heap.extend(self.tweets[followee])        
        return [t[1] for t in sorted(heap, key=lambda x: x[0], reverse=True)][:10]
        
    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId != followeeId:
            self.followers[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.followers[followerId]:
            self.followers[followerId].remove(followeeId)
