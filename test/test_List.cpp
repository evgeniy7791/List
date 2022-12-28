#include "List.h"

#include <gtest.h>


TEST(List, can_create_list_1)
{
    ASSERT_NO_THROW(List<int> list);
}


TEST(List, can_create_list_2)
{
    ASSERT_NO_THROW(List<int> list(15));
}

TEST(List, can_create_list_3)
{

    ASSERT_NO_THROW(List<int> list(15));
}

TEST(List, isEmpty)
{
    List<int> list(15);
    EXPECT_EQ(0, list.isEmpty());
}

TEST(List, isEmpty2)
{
    List<int> list(15);
    list.popBack();
    EXPECT_EQ(1, list.isEmpty());
}

TEST(List, isEmpty3)
{
    List<int> list(15);
    list.popFront();
    EXPECT_EQ(1, list.isEmpty());
}


TEST(List, get_size_1)
{
    List<int> list(7);
    list.pushBack(30);
    list.pushBack(12);
    EXPECT_EQ(list.getSize(), 3);
}

TEST(List, get_size_2)
{
    List<int> list(5);
    list.pushBack(30);
    list.pushBack(12);
    list.popFront();
    EXPECT_EQ(list.getSize(), 2);
}

TEST(List, pushback)
{
    List<int> list;
    list.pushBack(34);
    EXPECT_EQ(list.popBack(), 34);
}

TEST(List, can_create_copy_list)
{
    List<int> list;
    list.pushBack(3);
    ASSERT_NO_THROW(List<int> list2(list));
}

TEST(List, can_not_delete_from_empty_list)
{
    List<int> list;
    EXPECT_ANY_THROW(list.popFront());
}

TEST(List, can_assign_list_to_another_list)
{
    List<int> list;
    list.pushBack(3);
    List<int> list2;
    ASSERT_NO_THROW(list2 = list);
}


TEST(List, push_pop1)
{
    List<int> list(5);
    list.pushBack(10);
    list.pushBack(4);
    list.pushFront(2);
    EXPECT_EQ(2, list.popFront());
}

TEST(List, insertNext)
{
    List<int> list;
    list.pushBack(356);
    list.pushBack(4654);
    list.pushFront(2);
    list.insertNext(list.find(356),12);
    list.popBack();
    EXPECT_EQ(12, list.popBack());
}

TEST(List, deleteNext)
{
    List<int> list;
    list.pushBack(356);
    list.pushBack(4654);
    list.pushFront(2);
    list.deleteNext(list.find(2));
    list.popFront();
    EXPECT_EQ(4654, list.popFront());
}

TEST(List, reverse1)
{
    List<int> list;
    list.pushBack(3);
    list.pushBack(4);
    list.pushFront(2);
    list.reverse();
    EXPECT_EQ(4, list.popFront());
}

TEST(List, reverse2)
{
    List<int> list;
    list.pushBack(3);
    list.pushBack(4);
    list.pushFront(2);
    list.reverse();
    list.reverse();
    EXPECT_EQ(2, list.popFront());
}

TEST(List, push_pop)
{
    List<int> list(8);
    list.pushBack(3);
    list.pushBack(4);
    list.pushFront(2); 
    list.popBack();
    list.popFront();

    EXPECT_EQ(8, list.popFront());
    EXPECT_EQ(3, list.popFront());
}

TEST(List, getSize3)
{
    List<int> list(8);
    list.pushBack(3);
    list.pushBack(4);
    list.pushFront(2);
    list.popBack();
    list.popFront();

    EXPECT_EQ(2, list.getSize());
}

TEST(List, ex1)
{
    List<int> list;
    ASSERT_ANY_THROW(list.popBack());
}

TEST(List, ex2)
{
    List<int> list;
    ASSERT_ANY_THROW(list.popFront());
}

TEST(List, ex3)
{
    List<int> list;
    ASSERT_NO_THROW(list.clear());
}

TEST(List, find)
{
    List<int> list(8);
    list.pushBack(3);
    list.pushBack(4);
    EXPECT_EQ(3, list.find(3)->value);
}

TEST(List, SKOBKI_MARKA_1)
{
    List<int> list(8);
    list.pushBack(3);
    list.pushBack(4);
    EXPECT_EQ(3, list[1]);
}

TEST(List, SKOBKI_MARKA_2222)
{
    List<int> list(8);
    list.pushBack(3);
    list.pushBack(4);
    list[0] = 777;
    EXPECT_EQ(777, list.popFront());
}








