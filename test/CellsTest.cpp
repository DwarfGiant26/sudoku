#include <gtest/gtest.h>
#include "../Cells.h"

// Test for Constructor and Destructor
TEST(CellsTest, ConstructorDestructor) {
    Cells c(9);
    // Simply creating an instance tests the constructor.
    // The destructor will be called at the end of this scope.
}

// Test for setting and getting values
TEST(CellsTest, SetValueGetValue) {
    Cells c(9);

    c.setValue(3, 3, 42);
    ASSERT_EQ(42, c.getValue(3, 3));

    // Test out-of-bounds
    c.setValue(10, 10, 42);
    ASSERT_EQ(-1, c.getValue(10, 10)); // Here we're assuming your out-of-bounds value is -1
}

// Test for out-of-bounds retrieval
TEST(CellsTest, OutOfBoundsRetrieval) {
    Cells c(5);

    ASSERT_EQ(-1, c.getValue(10, 10));
    ASSERT_EQ(-1, c.getValue(-1, 3));
}

// Test for row validity
TEST(CellsTest, RowsValid) {
    Cells c(4);
    c.setValues(new int*[4]{
            new int[4]{1, 2, 3, 4},
            new int[4]{2, 3, 4, 1},
            new int[4]{3, 4, 1, 2},
            new int[4]{4, 1, 2, 3}
    });
    if(!c.isAllRowsValid()){
        ASSERT_TRUE(c.isRowValid(0));
        ASSERT_TRUE(c.isRowValid(1));
        ASSERT_TRUE(c.isRowValid(2));
        ASSERT_TRUE(c.isRowValid(3));
    }
}

TEST(CellsTest, RowsInvalid) {
    Cells c(4);
    c.setValues(new int*[4]{
            new int[4]{-1, 2, 3, 4},
            new int[4]{2, 2, 2, 2},
            new int[4]{10, 4, 1, 2},
            new int[4]{-1, -1, 4, 4}
    });
    ASSERT_FALSE(c.isAllRowsValid());
    ASSERT_FALSE(c.isRowValid(0)); // out-of-bounds in negative side
    ASSERT_FALSE(c.isRowValid(1)); // duplicates
    ASSERT_FALSE(c.isRowValid(2)); // out-of-bounds in positive side
    ASSERT_FALSE(c.isRowValid(3)); // combinations of out-of-bounds and duplicates
}

TEST(CellsTest, ColsValid) {
    Cells c(4);
    c.setValues(new int*[4]{
            new int[4]{1, 2, 3, 4},
            new int[4]{2, 3, 4, 1},
            new int[4]{3, 4, 1, 2},
            new int[4]{4, 1, 2, 3}
    });
    ASSERT_TRUE(c.isAllColsValid());
}

TEST(CellsTest, ColsInvalid) {
    Cells c(4);
    c.setValues(new int*[4]{
            new int[4]{-1, 2, 10, 4},
            new int[4]{2, 2, 2, -1},
            new int[4]{3, 4, 1, -1},
            new int[4]{4, 3, 4, 4}
    });
    ASSERT_FALSE(c.isAllColsValid());
    ASSERT_FALSE(c.isColValid(0)); // out-of-bounds in negative side
    ASSERT_FALSE(c.isColValid(1)); // duplicates
    ASSERT_FALSE(c.isColValid(2)); // out-of-bounds in positive side
    ASSERT_FALSE(c.isColValid(3)); // combinations of out-of-bounds and duplicates
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
