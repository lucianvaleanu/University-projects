# Social Network
 Program which simulates a social network as follows:

-The information is read from 3 files:
	a. Users: each user is identified by an unique name
	b. Topics of interest for users: each topic is an unique string and is followed by the list of users that have subscribed to the topic
	c. User's posts: each post has an id and it contains the post's text, timestamp (date and time) and the user who posted it.

-When the application is launched, a new window is created for each user. The window will contain 3 sections: feed, posts, and topic subscriptions.
	a. The feed is populated with all posts containing topics of interest to the user or mentions of his/her name.
	b. The posts section shows the user's posts sorted descending by timestamp.
	c. The subscriptions section shows a list of all topics the user has subscribed to.

-An user can subscribe to a topic. As the user types some text a list will show all topics matching that text. The user will choose the topic from the list and subscribe to it and the user's topics list is updated accordingly.

-An user can add a new post. Any new post added by an user will show in the user's posts section. A post shorter than 3 characters cannot be added. The added post's text can contain one or multiple '#' signs followed by topics or one or more '@' signs followed by an user name or combinations of these. For all '#' signs followed by topics the post will be shown in the feed of all users who are subscribed to the mentioned topic. The shown information is: the user who posted, the post's text and timestamp. For all '@' signs followed by user names the post will be shown in the feed of the users having that name. The shown information is: the user who posted, the post's text and timestamp.
An user can update a post's text. The feed of all users will be updated accordingly. These featured are made using the Observer Design Pattern.

-The feed will show posts in decreasing order of their creation. Posts where the user is mentioned (using '@') will be shown in blue.

-The topics of interest file and posts file are updated after all modifications.