#include "gtest.h"
#include "../Queue/queue.h"

TEST(Queue, can_create_queue_with_positive_size) {
	ASSERT_NO_THROW(TQueue<int> q(3));
}

TEST(Queue, cant_create_queue_with_negative_size) {
	ASSERT_ANY_THROW(TQueue<int> q(-1));
}

TEST(Queue, cant_create_queue_with_zero_size) {
	ASSERT_ANY_THROW(TQueue<int> q(0));
}

TEST(Queue, can_push_element) {
	TQueue<int> q(3);
	ASSERT_NO_THROW(q.push(2));
	EXPECT_EQ(2, q.front());
}

TEST(Queue, can_pop_element) {
	TQueue<int> q(5);
	q.push(3);
	q.push(4);
	EXPECT_EQ(3, q.pop());
	EXPECT_EQ(4, q.front());
}

TEST(Queue, cant_add_element_in_full_queue) {
	TQueue<int> q(2);
	q.push(1);
	q.push(2);
	ASSERT_ANY_THROW(q.push(3));
}

TEST(Queue, cant_pop_element_from_empty_queue) {
	TQueue<int> q(2);
	ASSERT_ANY_THROW(q.pop());
}

TEST(Queue, can_get_front_element) {
	TQueue<int> q(2);
	q.push(2);
	q.push(3);
	EXPECT_EQ(2, q.front());
}

TEST(Queue, can_assign_queue_of_equal_size) {
	TQueue<int> q1(3);
	q1.push(1);
	q1.push(2);

	TQueue<int> q2(1);
	q2.push(0);

	ASSERT_NO_THROW(q2 = q1);
	EXPECT_EQ(1, q2.front());
	ASSERT_NO_THROW(q2.pop(); q2.pop());
	ASSERT_ANY_THROW(q2.pop());
}