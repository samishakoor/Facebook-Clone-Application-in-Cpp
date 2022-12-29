#include <iostream>
#include<iomanip>
#include<string>
#include<windows.h>
using namespace std;


struct Activity
{
    string type;
    string value;

    Activity()
    {
        type = "1";
        value = "1";
    }
    Activity(string t, string v)
    {
        type = t;
        value = v;
    }
    string getActivityType()
    {
        return type;
    }
    string getActivityValue()
    {
        return value;
    }

};
struct Comment 
{
    string user_who_comment;
    string description;

    Comment()
    {
      user_who_comment="1";
      description="1";
    }
    Comment(string user, string des)
    {
        user_who_comment = user;
        description = des;
    
    }
    string getUserWhoComment()
    {
        return user_who_comment;
    }
    string getCommentDescription()
    {
        return description;
    }


};
struct People 
{
    int id;
    string username;

    People() 
    {
        id = '\0';
        username = '\0';
    }
};
struct PostUser 
{
    int user_id;
    string user_name;

    PostUser() 
    {
        user_id = 0;
        user_name = '\0';
    
    }
};
struct Date 
{
    int d;
    int m;
    int y;

    Date() 
    {
        d = 0;
        m = 0;
        y = 0;
    }

    void setDate(int day,int month,int year) 
    {
        d = day;
        m = month;
        y = year;
    }

    Date GetDate() 
    {
        Date d1;
        d1.d = d;
        d1.m = m;
        d1.y = y;
        return d1;
    }

};


class Post
{
    int postId;
    string description;
    Activity act;

    PostUser user_who_shared_post;

    int no_of_likes;

    People* peopleList;

    Date postDate;

    Comment* commentsList;
    int no_of_comments;

public:

    Post()
    {
        postId = 0;
        description = '\0';
        no_of_comments = 0;
        no_of_likes = 0;
    }

    Post(int id, string des, Date date)
    {
        postId = id;
        description = des;
        postDate = date;

        act.type = "1";
        act.value = "1";

        no_of_comments = 0;

        peopleList = new People[10];
        commentsList = new Comment[100];

        for (int i = 0; i < 100; i++)
        {
            commentsList->user_who_comment = "1";
            commentsList->description = "1";
        }
    }

    void setActivityForPost(Activity new_activity)
    {
        act.type = new_activity.type;
        act.value = new_activity.value;
    }

    void setPostUser(PostUser user_obj)
    {
        user_who_shared_post.user_id = user_obj.user_id;
        user_who_shared_post.user_name = user_obj.user_name;
    }
    PostUser getPostUser() 
    {
        return  user_who_shared_post;
    }


    Activity getActivity() 
    {
        return act;
    }
    int getId()
    {
        return postId;
    }
    string getDescription()
    {
        return description;
    }
    Date getDate() 
    {
        return postDate;
    }
    int get_no_ofLikes()
    {
        return no_of_likes;
    }

    
    int maxLikes() 
    {
        if (no_of_likes < 10) 
        {
            no_of_likes++;
            return no_of_likes;
        }
        else 
        {
            return -1;
        }
    }

    void ListOfPeopleWhoLiked(People p) 
    {
        int likes = maxLikes();
        if (likes != -1)
        {
            peopleList[likes-1].id=p.id;
            peopleList[likes - 1].username = p.username;
        }
        else 
        {
            cout << " ERROR : more than 10 people can't like a post!" << endl;
        }
    }

    People* getListofPoepleWhoLiked() 
    {
        return peopleList;
    }

    void display_no_of_likes_on_post() 
    {
        cout<<"A post having id '"<<postId<<"' has "<< no_of_likes <<" likes" << endl;
    }

    void addComment(Comment com)
    {

        commentsList[no_of_comments] = com;
        no_of_comments++;


        if (no_of_comments == 100)
        {
            cout << "comments limit reached!" << endl;
        }
    }

    Comment* getCommentsOnPost() 
    {
        return commentsList;
    }

    int getNo_of_CommentsOnPost() 
    {
        return no_of_comments;
    }

    void viewListOfPeopleWhoLikePost()
    {
        cout << endl;
        cout <<"Following People liked the post with ID:"<<postId<<endl;
        for (int i = 0; i<no_of_likes; i++)
        {
            cout<< peopleList[i].username << endl;
        }
    }

};

class Memory 
{
    Post* ptr;

public:
    Memory() 
    {
        ptr = nullptr;
    }
    void shareMemory(Post p,string str,Date date_obj) 
    {
        ptr = &p;


        int postDate=p.getDate().y;
        int memoryDate=date_obj.y;
        if (memoryDate > postDate)
        {

            cout << endl << "~~~ " << ptr->getPostUser().user_name << " shared a memory ~~~" << "  ... " << "(" << date_obj.d << "/" << date_obj.m << "/" << date_obj.y << ")" << endl << "\"" << str << "...\"" << endl;
            cout << setw(30) << "(" << memoryDate - postDate << " years Ago)" << endl;
            Activity act = ptr->getActivity();
            if (act.type == "1" && act.value == "1")
            {
                cout << endl << ptr->getPostUser().user_name << " shared " << "\"" << ptr->getDescription() << "\"" << " ... " << "(" << p.getDate().d << "/" << p.getDate().m << "/" << p.getDate().y << ")" << endl;
            }
            if (act.type != "1" && act.value != "1")
            {
                cout << endl << ptr->getPostUser().user_name << " is " << act.type << " " << act.value << "." << endl << "\"" << ptr->getDescription() << "\"" << " ... " << "(" << p.getDate().d << "/" << p.getDate().m << "/" << p.getDate().y << ")" << endl;
            }
        }
    }

};

class Page
{
    int pageId;
    string pageTitle;
    Post* postList;
    int no_of_posts;
    int no_of_people;

public:
    Page()
    {
        pageId = 0;
        pageTitle = '\0';
        no_of_people = 0;
        no_of_posts = 0;
    }
    Page(int id, string title)
    {
        pageId = id;
        pageTitle = title;
        no_of_people = 0;
        no_of_posts = 0;

        postList = new Post[100];
    }


    void addPostByPage(Post new_post)
    {
       
        postList[no_of_posts] = new_post;
        no_of_posts++;

        if (no_of_posts == 100)
        {
            cout << "Sorry You could not Post as Posts Limit Reached!" << endl;
        }
    }

    Post* getPosts()
    {
        return postList;
    }

    int getMaxPosts()
    {
        return no_of_posts;
    }

    int getPageId()
    {
        return pageId;
    }
    string getPageTitle()
    {
        return pageTitle;
    }



    void no_of_people_liked_page(int n_people)
    {
        no_of_people = no_of_people + n_people;
    }

    void viewLikesofPage()
    {
        cout << endl << pageTitle << " has " << no_of_people << " likes" << endl;
    }

    bool checkIfSameUserLikesAPostMoreThanOnce(Post p_obj)
    {
        People* list = p_obj.getListofPoepleWhoLiked();

        for (int i = 0; i < p_obj.get_no_ofLikes(); i++)
        {
            if (pageId == list[i].id)
            {
                return true;
            }

        }
        return false;
    }
    void pageLikeAPost(Post& p)
    {
        if (!checkIfSameUserLikesAPostMoreThanOnce(p))
        {
            People ppl;
            ppl.id = getPageId();
            ppl.username = getPageTitle();
            p.ListOfPeopleWhoLiked(ppl);
        }
        else
        {
            cout << endl << "Sorry " << pageTitle << " , you cannot like a post with ID '" << p.getId() << "' more than once!" << endl;
        }
    }


    



};

struct Friends
{
    int friendId;
    string friendName;

    Friends()
    {
        friendId = 0;
        friendName = '\0';
    }

    Friends(int id, string name)
    {
        friendId = id;
        friendName = name;
    }
};

class User
{
    int userId;
    string userName;
    int maxFriends;
    int maxPages;
    Friends* friendsList;
    Page* pagesList;

public:
    User()
    {
        userId = 0;
        userName = '\0';
        maxFriends = 0;
        maxPages = 0;
    }
    User(int id, string name)
    {
        userId = id;
        userName = name;
        cout << userName << " successfully set as current user !" << endl;
        maxFriends = 0;
        maxPages = 0;
        friendsList = new Friends[10];
        pagesList = new Page[10];
    }

    void setUser(int id, string name)
    {
        this->userId = id;
        this->userName = name;
    }

    string getUserName()
    {
        return userName;
    }
    int getUserId()
    {
        return userId;
    }

    void addPostByUser(Post &p) 
    {
        PostUser user;
        user.user_id = userId;
        user.user_name = userName;
        p.setPostUser(user);
    }

    bool checkFriendsFromSameId(int friendId)
    {
        if (maxFriends == 0)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < maxFriends; i++)
            {
                if (friendsList[i].friendId == friendId)
                {
                    return true;
                    break;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    void addFriend(User u)
    {
        if (checkFriendsFromSameId(u.userId) == false)
        {
            Friends fnd(u.userId, u.userName);
            friendsList[maxFriends] = fnd;
            maxFriends++;
        }
        if (maxFriends == 10)
        {
            cout << endl << "Maximum Friends Limit Reached !!!" << endl;
        }
    }

    bool checkLikesFromSameId(Page p)
    {
        if (maxPages == 0)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < maxPages; i++)
            {
                if (pagesList[i].getPageId() == p.getPageId())
                {
                    return true;
                    break;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    void no_of_likes_of_Page(Page& p)
    {
        p.no_of_people_liked_page(1);
    }

    void LikePage(Page& pg)
    {
        if (checkLikesFromSameId(pg) == false)
        {
            pagesList[maxPages] = pg;
            no_of_likes_of_Page(pg);
            maxPages++;
        }

        if (maxFriends == 10)
        {
            cout << endl << "Maximum Pages Limit Reached !!!" << endl;
        }
    }
   
    void viewLikedPages()
    {
        cout << endl<< userName << " - LikedPages " << endl<< endl;
        for (int i = 0; i < maxPages; i++)
        {
            int pageid = pagesList[i].getPageId();
            string pagetitle = pagesList[i].getPageTitle();
            cout << "p" << pageid << " - " << pagetitle << endl;
        }
    }
    void viewFriendsList()
    {

        cout << endl << userName << " - FriendsList " << endl
            << endl;
        for (int i = 0; i < maxFriends; i++)
        {
            Friends fnd;
            fnd.friendId = friendsList[i].friendId;
            fnd.friendName = friendsList[i].friendName;

            cout << "u" << fnd.friendId << " - " << fnd.friendName << endl;
        }
    }

    bool checkFriend(User obj_user)
    {
        for (int i = 0; i < maxFriends; i++)
        {
            if (friendsList[i].friendId == obj_user.userId)
            {
                return true;
            }
        }
        return false;
    }
    void viewFriendPosts(User obj_user, Post p)
    {
        PostUser u=p.getPostUser();
        int postuserId=u.user_id;
        cout <<endl<< endl;
        if (checkFriend(obj_user) && obj_user.getUserId() == postuserId)
        {
            Activity act = p.getActivity();
            if (act.type == "1" && act.value == "1")
            {
                cout  << obj_user.userName << " shared " << "\"" << p.getDescription() << "\"" ;
            }
            if (act.type != "1" && act.value != "1")
            {
                cout  << obj_user.userName << " is " << act.type << " " << act.value << "." << endl << "\"" << p.getDescription() << "\"" ;
            }
            cout << "   ... " <<p.getDate().d<<"/"<< p.getDate().m<<"/"<< p.getDate().y << endl;
        }
    }

    bool checkIfPostExistsOnPage(Page page_obj, Post post_obj)
    {
        Post* postptr = page_obj.getPosts();
        int post_id = post_obj.getId();
        int number_of_posts = page_obj.getMaxPosts();
        for (int i = 0; i < number_of_posts; i++)
        {
            if (postptr->getId() == post_id)
            {
                return true;
                break;
            }
            postptr++;
        }

        cout << "The post you want to view does not exits on " << "\"" << page_obj.getPageTitle() << "\"" << endl;
        return false;
    }
    void viewPagePosts(Page p, Post post_obj)
    {
        if (checkIfPostExistsOnPage(p,post_obj))
        {
            Post* postptr = p.getPosts();
            int number_of_posts = p.getMaxPosts();

            for (int i = 0; i < number_of_posts; i++)
            {
                if (postptr->getId() == post_obj.getId())
                {
                    Activity act = postptr->getActivity();

                    if (act.type == "1" && act.value == "1")
                    {
                        cout <<endl<<endl<< endl << p.getPageTitle() << " shared " << "\"" << postptr->getDescription() << "\"";
                    }
                    if (act.type != "1" && act.value != "1")
                    {
                        cout <<endl<<endl<< endl << p.getPageTitle() << " is " << act.type << " " << act.value << "." << endl << "\"" << postptr->getDescription() << "\"";
                    }
                    cout << "   ... " << postptr->getDate().d<<"/"<< postptr->getDate().m<<"/"<< postptr->getDate().y << endl;
                    break;
                }
                postptr++;
            }
        }
    }

    void addCommentToPostOfPage(Page page_obj, Post post_obj , string comment) 
    {
        bool checkIfPostExistsOnPage = false;

        Post* postptr = page_obj.getPosts();
        int post_id = post_obj.getId();
        int number_of_posts = page_obj.getMaxPosts();

        Comment c;
        c.user_who_comment = userName;
        c.description = comment;

        for (int i=0 ;i<number_of_posts ;i++)
        {
            if (postptr->getId() == post_id) 
            {
                postptr->addComment(c);
                checkIfPostExistsOnPage = true;
                break;
            }
            postptr++;
        }
        
        if (!checkIfPostExistsOnPage) 
        {
            cout <<endl<< "ERROR:The post on which you want to comment does not exits on " << "\"" << page_obj.getPageTitle() << "\"" << endl;
        }
    }
    void showCommentOnPostOfPage(Page page_obj, Post post_obj)
    {
                Post* postptr = page_obj.getPosts();
                int post_id = post_obj.getId();
                int number_of_posts = page_obj.getMaxPosts();

                Comment* comments = postptr->getCommentsOnPost();
                string commentUser = comments->getUserWhoComment();
                string commentDescription = comments->getCommentDescription();
                int no_of_comments = postptr->getNo_of_CommentsOnPost();

                for (int i = 0; i < number_of_posts; i++)
                {
                    if (postptr->getId() == post_id)
                    {
                        for (int i = 0; i < no_of_comments; i++)
                        {
                            if (commentUser != "1" && commentDescription != "1")
                            {
                                cout << setw(15) << comments->getUserWhoComment() << " wrote : " << "\"" << comments->getCommentDescription() << "\"" << endl;
                            }
                            comments++;
                        }
                
                            break;
                    }
                    postptr++;
                }

                if (commentUser == "1" && commentDescription == "1") 
                {
                    cout << "There are no comments on this post to show !!!" << endl;
                }
    }

    void addCommentToPost(Post &p ,string comment) 
    {
        Comment c;
        c.user_who_comment = userName;
        c.description = comment;
        p.addComment(c);
        
    }

    void showCommentsOnPost(Post p) 
    {
        Comment *comments =p.getCommentsOnPost();
        int no_of_comments = p.getNo_of_CommentsOnPost();

        string commentUser = comments->getUserWhoComment();
        string commentDescription = comments->getCommentDescription();

        for (int i = 0; i < no_of_comments; i++)
        {
            if (commentUser!="1" && commentDescription!="1")
            {
                cout << setw(15) << comments->getUserWhoComment() << " wrote : " << "\"" << comments->getCommentDescription() << "\"" << endl;
            }
            comments++;
        }

        if (commentUser == "1" && commentDescription == "1") 
        {
            cout << "There are no comments on this post to show !!!" << endl;
        }
        cout << endl << endl;
    }
    void viewTimeLinePost(Post timeline_post) 
    {
            Activity act = timeline_post.getActivity();
            if (act.type == "1" && act.value == "1")
            {
                cout << endl << userName << " shared " << "\"" << timeline_post.getDescription() << "\"" <<" ... "<<"("<< timeline_post.getDate().d << "/" << timeline_post.getDate().m << "/" << timeline_post.getDate().y<<")"<<endl;
            }
            if (act.type != "1" && act.value != "1")
            {
                cout << endl << userName << " is " << act.type << " " << act.value << "." << endl << "\"" << timeline_post.getDescription() << "\"" << " ... " << "(" << timeline_post.getDate().d << "/" << timeline_post.getDate().m << "/" << timeline_post.getDate().y << ")" << endl;
            }

            showCommentsOnPost(timeline_post);
    }

    bool checkIfSameUserLikesAPostMoreThanOnce(Post p_obj)
    {
        People* list = p_obj.getListofPoepleWhoLiked();
    
        for (int i = 0; i < p_obj.get_no_ofLikes(); i++) 
        {
            if (userId==list[i].id)
            {
                return true;
            }
        
        }
        return false;
    }
    void userLikeAPost(Post& p) 
    {
        if (!checkIfSameUserLikesAPostMoreThanOnce(p))
        {
            People ppl;
            ppl.id = getUserId();
            ppl.username = getUserName();
            p.ListOfPeopleWhoLiked(ppl);
        }
        else 
        {
            cout <<endl<< "Sorry "<<userName<<" , you cannot like a post with ID '"<<p.getId()<< "' more than once!" << endl;
        }
    }

    void displayPost(Post p)
    {
        Activity post_act = p.getActivity();
        PostUser post_user = p.getPostUser();

        if (post_act.type == "1" && post_act.value == "1")
        {
            cout << endl << post_user.user_name << " shared " << "\"" << p.getDescription() << "\"" << endl;
        }
        if (post_act.type != "1" && post_act.value != "1")
        {
            cout << endl << post_user.user_name << " is " << post_act.type << " " << post_act.value << "." << endl << "\"" << p.getDescription() << "\"" << endl;
        }
        showCommentsOnPost(p);
    }

    void viewPage(Page pageobj)
    {
        cout<<setw(50) << pageobj.getPageTitle() << endl;

        Post* postptr = pageobj.getPosts();
        int number_of_posts = pageobj.getMaxPosts();

        for (int i = 0; i < number_of_posts; i++)
        {
            Activity act = postptr->getActivity();
            Comment* comment = postptr->getCommentsOnPost();

            if (act.type == "1" && act.value == "1")
            {
                cout << endl << pageobj.getPageTitle() << " shared " << "\"" << postptr->getDescription() << "\"" ;
            }
            if (act.type != "1" && act.value != "1")
            {
                cout << endl << pageobj.getPageTitle() << " is " << act.type << " " << act.value << "." << endl << "\"" << postptr->getDescription() << "\"" ;
            }
            cout << "   ... " << postptr->getDate().d << "/" << postptr->getDate().m << "/" << postptr->getDate().y << endl;
            for (int i = 0; i < postptr->getNo_of_CommentsOnPost(); i++)
            {
                if (comment->description != "1" && comment->user_who_comment != "1")
                {
                    cout << setw(15) << comment->getUserWhoComment() << " wrote : " << "\"" << comment->getCommentDescription() << "\"" << endl;
                }
                comment++;
            }

            cout << endl << endl;
            postptr++;
        }
        
    }

    void viewMemory(Post p , string str,Date d) 
    {
        Memory m;
        m.shareMemory(p,str,d);
    }

};

int main()
{ 
    //current user
    User u1(5, "Sami Shakoor");

    //creating Pages 
    Page p1(2, "Al-Jazeera");
    Page p2(5, "Food Fusion");
    Page p3(6, "PCB");
    
    //creating  friend users of current user
    User u6,u7,u8,u9,u10,u11;
    //users who are friend of current user
    u6.setUser(3, "Ali");
    u7.setUser(14, "Haseeb");
    u8.setUser(12, "Mahd");
    //random users (may be for commenting on posts)
    u9.setUser(3, "Ali");
    u10.setUser(78, "Haseeb");
    u11.setUser(12, "Mahd");
    cout << endl << setw(50) << u1.getUserName() << "'s Friend List " << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    // add friends for current user
    u1.addFriend(u6);
    u1.addFriend(u7);
    u1.addFriend(u8);
    // display friends list of current user
    u1.viewFriendsList();

    cout << endl << setw(50) << u1.getUserName() << "'s Liked Pages " << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    //Liked pages for current user
    u1.LikePage(p1);
    u1.LikePage(p2);
    u1.LikePage(p3);
    //display list of pages liked by current user
    u1.viewLikedPages();


    /*
        //  Displaying no of likes of each(particular) page liked by users (friends,other users,may be current user )
            User u2(52, "Obaid");
            User u3(70, "Aqib");
            User u4(30, "Amjad");
            User u5(31, "saif");




            u2.LikePage(p2);
            u2.LikePage(p1);
            u3.LikePage(p1);
            u4.LikePage(p1);
            u5.LikePage(p1);
            u2.LikePage(p3);
            u3.LikePage(p3);



            p1.viewLikesofPage();
            cout << endl;

            p2.viewLikesofPage();
            cout << endl;

            p3.viewLikesofPage();
            cout << endl;
        */

        cout << endl << setw(50) << u1.getUserName() << " - HOMEPAGE " << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

        //setting dates for posts
        Date d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11,d12;
        d1.setDate(13, 10, 2019);
        d2.setDate(16, 10, 2019);
        d3.setDate(18, 10, 2019);
        d4.setDate(1, 11, 2019);
        d5.setDate(7, 11, 2020);
        d6.setDate(9, 11, 2020);
        d7.setDate(19, 11, 2020);
        d8.setDate(25, 11, 2020);
        d9.setDate(13, 12, 2020); 
        d10.setDate(17, 12, 2020);
        d11.setDate(21, 12, 2021);
       
        //creating Posts for pages
        Post P1(1, "Oil drilling in Alaska's indigenous communities is on the table again", d1);
        Post P2(5, "Try this dish at home...", d2);
        Post P3(6, "We Won the Match!", d3);
        Post P7(4, "Today,we will make brownies!",d7);
        //creating Posts for friends
        Post P4(2, "OOP Project Started yet", d4);
        Post P5(7, "Waiting for weekend", d5);
        Post P6(3, "Waiting for result", d6);
        Post P11(19, "Sunday Special Breakfast for our followers", d11);

        //creating Activity for Posts of Pages
        Activity A1("making", "Kashmiri Chai");
        P2.setActivityForPost(A1);
        Activity A2("feeling", "happy");
        P3.setActivityForPost(A2);
        Activity A8("making", "Halwa Poori");
        P11.setActivityForPost(A8);


        //creating Activity for Posts shared by current user friends
        Activity A3("feeling", "motivated");
        P4.setActivityForPost(A3);
        Activity A4("feeling", "excited");
        P6.setActivityForPost(A4);

        //posts shared by pages
        p1.addPostByPage(P1);
        p2.addPostByPage(P2);
        p3.addPostByPage(P3);
        p2.addPostByPage(P7);
        p2.addPostByPage(P11);
        
        //posts shared by other users (friends etc)
        u6.addPostByUser(P4);
        u7.addPostByUser(P5);
        u8.addPostByUser(P6);

        
        //adding comments to posts of Pages
        u1.addCommentToPostOfPage(p2, P2, "Hmmm! Delicious");
        u11.addCommentToPostOfPage(p2, P2, "WOW! Kashmiri Tea");
        u7.addCommentToPostOfPage(p3, P3, "Hurrah ! We have won the match");


        //displaying posts of each page while showing the comments on posts of their respective page
        u1.viewPagePosts(p1,P1);
        u1.viewPagePosts(p2,P2);
        u1.showCommentOnPostOfPage(p2, P2);
        u1.viewPagePosts(p2, P7);
        u1.viewPagePosts(p3,P3);
        u1.showCommentOnPostOfPage(p3, P3);


       //adding comments to posts
        u10.addCommentToPost(P4, "Complete it on time");
        u9.addCommentToPost(P6, "goodLuck");
        u10.addCommentToPost(P6, "God Bless you");
        u11.addCommentToPost(P5, "Are you planning for a trip on weekend?");

        //displaying posts posted by friend users of current user while displaying comments to posts
        u1.viewFriendPosts(u6, P4);
        u1.showCommentsOnPost(P4);
        u1.viewFriendPosts(u7, P5);
        u1.showCommentsOnPost(P5);
        u1.viewFriendPosts(u8, P6);
        u1.showCommentsOnPost(P6);
        

        cout << setw(50) << u1.getUserName() << " - TIMELINE " << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    
        //adding postsfor current user timeline
        Post P8(51, "Happy Birthday to my dear Mom", d8);
        Post P9(43, "Happy Birthday to my dear Uncle", d9);
        Post P10(21, "Got D in toughest subject Thanks God I am Pass finally", d10);

        //posts shared by current user 
        u1.addPostByUser(P8);
        u1.addPostByUser(P9);
        u1.addPostByUser(P10);


        //adding activities for current user timeline-posts
        Activity A5("celebrationg", "birthday");
        P8.setActivityForPost(A5);
        Activity A6("celebarting", "birthday");
        P9.setActivityForPost(A6);
        Activity A7("celebrating", "success");
        P10.setActivityForPost(A7);

        //adding comments to posts
        u6.addCommentToPost(P8, "Happy Birthday dear mom");
        u7.addCommentToPost(P9, "Happy Birthday dear uncle");
        u8.addCommentToPost(P10, "Celebrations ???");
        u1.addCommentToPost(P10, "Thanks for wishes");

        //displaying posts of current user's timeline while displaying comments
        u1.viewTimeLinePost(P8);
        u1.viewTimeLinePost(P9);
        u1.viewTimeLinePost(P10);
      

        // people(users) and pages liking a post 
        u1.userLikeAPost(P3);
        u6.userLikeAPost(P3);
        u10.userLikeAPost(P3);
        p1.pageLikeAPost(P3);
        u8.userLikeAPost(P3);

        u7.userLikeAPost(P1);
        u11.userLikeAPost(P1);
        u9.userLikeAPost(P1);

        u10.userLikeAPost(P7);
        u6.userLikeAPost(P7);
        p3.pageLikeAPost(P7);
        u1.userLikeAPost(P7);

/*
        //display no_of likes on a specific post
        //P3.display_no_of_likes_on_post();
        //P1.display_no_of_likes_on_post();
        //P7.display_no_of_likes_on_post();
        */

        cout << setw(70) <<"List of People Who Liked Posts" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;

        //displaying list of those people who liked a particular post
        P3.viewListOfPeopleWhoLikePost();
        P1.viewListOfPeopleWhoLikePost();
        P7.viewListOfPeopleWhoLikePost();

        cout << endl << setw(70) << "Displaying a particular post "<< endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        //displaying a particular post
        u1.addPostByUser(P5);
        u1.displayPost(P5);

        cout <<endl<< setw(70) << "List of all the Posts shared by "<<"\""<< p2.getPageTitle() << "\"" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        //displaying all the posts of  particular given page
        u1.viewPage(p2);
        
        cout << endl << setw(70) << "Memories shared by " << "\"" << u1.getUserName()<< "\"" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        //sharing memory by current user
        d12.setDate(21, 12, 2022);//setting date for memory
        u1.viewMemory(P10, "Never thought I will be specialist in this field",d12);

    return 0;
}
