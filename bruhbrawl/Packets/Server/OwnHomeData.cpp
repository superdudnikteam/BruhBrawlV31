#include "bytestrimer.cpp"
class OwnHomeDataMessage
{
	public:
	ByteStream bs;
	void encode(int sock);
};
void OwnHomeDataMessage::encode(int sock)
{
	bs.writeVInt(0);
	bs.writeVInt(0);
	bs.writeVInt(-1);//trophies
    bs.writeVInt(99999);
    bs.writeVInt(99999);

    bs.writeVInt(1);
    bs.writeVInt(275);
    bs.writeVInt(28);
    bs.writeVInt(4);
    bs.writeVInt(43);
    bs.writeVInt(9);

    bs.writeVInt(0);
    bs.writeVInt(0);//selected skins array
    bs.writeVInt(0);//unlocked
    bs.writeVInt(0);
    bs.writeVInt(0);// Leaderboard Global TID
    bs.writeVInt(10000);// Trophy Road Reached Icon
    bs.writeVInt(0);// Unknown
    bs.writeVInt(0);// Unknown

    bs.add(1,0);// Is Token Limit Reached
    bs.writeVInt(1000);
    bs.writeVInt(0); // Trophy Road Timer
    bs.writeVInt(0);      // Power Play Timer
    bs.writeVInt(0);  // Brawl Pass Timer

    bs.writeVInt(0);  // Unknown
    bs.add(1,0);
    bs.add(1,0);
    bs.add(1,4);// Shop Token Doubler//
    bs.writeVInt(2); // Unknown
    bs.writeVInt(2); // Unknown
    bs.writeVInt(2); // Unknown

    bs.writeVInt(1); // Name Change Cost
    bs.writeVInt(30); // Name Change Timer

    bs.writeVInt(1);
    {
    	bs.writeVInt(3);
    	for (const auto i: {16,1,8})
    	{
    		bs.writeVInt(i);//id
    		bs.writeVInt(777);//count
    		bs.writeVInt(16);
    		bs.writeVInt(41);
    		bs.writeVInt(0);
    	}
    	bs.writeVInt(0);
    	bs.writeVInt(0);//cost
    	bs.writeVInt(3600);//timer
    	bs.writeVInt(1);
    	bs.writeVInt(100);
    	bs.add(1,0);//bool
    	bs.add(1,0);//?
    	bs.add(1,0);//daily
    	bs.add(1,0);
    	bs.writeVInt(0);
    	bs.add(4,0);
    	bs.writeStringRef("S.B. SUCKS HUGE COCK!!");
    	bs.add(1,0);
    	bs.writeString("");//theme
    	bs.writeVInt(0);
    	bs.add(1,0);
    	bs.writeVInt(2);
    	bs.writeVInt(9339);//%
    }

    bs.writeVInt(0);  // AdStatus

    bs.writeVInt(25565); // Available Battle Tokens
    bs.writeVInt(10);   // Time till Bonus Tokens

    bs.writeVInt(0);  // tickets

    bs.writeVInt(0);
    bs.writeVInt(0);  // tickets event array

    bs.writeVInt(16);
    bs.writeVInt(41);//dataref, brawlerID

    bs.writeString("UA");
    bs.writeString("S.B. SUCKS!");
    bs.writeVInt(0);  //trophy anim array

    bs.writeVInt(0);  // CooldownEntry

    bs.writeVInt(1); // BrawlPassSeasonData
        {
            bs.writeVInt(3);
            bs.writeVInt(-1);
            bs.add(1,1);
            bs.writeVInt(0);
            bs.add(1,0);
        }
    bs.writeVInt(0);  //cum
        
    bs.add(1,1);// quests bool
    bs.writeVInt(0);
    bs.add(1,1);//emotes bool
    bs.writeVInt(0);
        //shop boxes
    bs.writeVInt(0);//timestamp
    bs.writeVInt(6);
    bs.writeVInt(0);
    bs.writeVInt(30);//cost
    bs.writeVInt(80);//cost x2
    bs.writeVInt(170);
    bs.writeVInt(350);
        //end
    bs.writeVInt(0);
        //events sex
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeVInt(0);
        //shop resourses
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeVInt(1);//bool
    bs.writeVInt(0);
    bs.writeVInt(1);//array count
    bs.add(4,1);//championship index?
    bs.add(4,41000000+18);//menu theme I
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.add(4,0);
    bs.add(4,1);
    bs.writeVInt(1);//array
    {
    	bs.writeVInt(81);
    	bs.add(4,0);
    	bs.add(1,0);
    	bs.add(4, 3600);
    	bs.writeString("S.B. SUCKS");
    	bs.writeVInt(1);
    }
    bs.writeVInt(0);//array
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeVInt(0);//highID
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeString("sb sucks");
    bs.writeVInt(1);//bool
    bs.add(4,0);
    bs.writeVInt(8);//count
    {
    	bs.writeVInt(326);
    	for (int i = 0; i < 322; i++)
    	{
    		bs.writeVInt(23);
    		bs.writeVInt(i);
    		bs.writeVInt(1);
    	}
    	bs.writeVInt(5);
    	bs.writeVInt(1);
    	bs.writeVInt(500);//brawl boxes tokens
    	bs.writeVInt(5);
    	bs.writeVInt(8);
    	bs.writeVInt(777);//gold
    	bs.writeVInt(5);
    	bs.writeVInt(9);
    	bs.writeVInt(50);//big box tokens
    	bs.writeVInt(5);
    	bs.writeVInt(10);
    	bs.writeVInt(9339);//starpoints
    	
    	bs.writeVInt(0);//brawler trophies arraynik
    	bs.writeVInt(0);//for rank
    	bs.writeVInt(0);//?
    	bs.writeVInt(0);//upgrade points arraynik
    	bs.writeVInt(42);//power lvl arraynik
    	for (int i = 0; i < 42; i++)
    	{
    		bs.writeVInt(16);
    		bs.writeVInt(i);
    		bs.writeVInt(9);
    	}
    	bs.writeVInt(0);
    	bs.writeVInt(0);
    }
    bs.writeVInt(25565);//plr gems
    bs.writeVInt(10);//free gems
        
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeVInt(0);
    bs.writeVInt(2);//tutorial
	bs.writeVInt(0);
	bs.write(24101, sock);
}