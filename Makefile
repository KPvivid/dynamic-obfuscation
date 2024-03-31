CC = g++
CFLAGS = -Wall -Wextra -std=c++11
SRCDIR = src
BUILDDIR = build
TARGET1 = simple
TARGET2 = obfuscated

# List of source files for each target
TARGET1_SRCS = $(wildcard $(SRCDIR)/$(TARGET1)/*.cpp)
TARGET2_SRCS = $(wildcard $(SRCDIR)/$(TARGET2)/*.cpp)

TARGET1_OBJS = $(TARGET1_SRCS:$(SRCDIR)/$(TARGET1)/%.cpp=$(BUILDDIR)/$(TARGET1)/%.o)
TARGET2_OBJS = $(TARGET2_SRCS:$(SRCDIR)/$(TARGET2)/%.cpp=$(BUILDDIR)/$(TARGET2)/%.o)
DEPS = $(TARGET1_OBJS:.o=.d) $(TARGET2_OBJS:.o=.d)

.PHONY: all clean

all: $(TARGET1) $(TARGET2)

$(TARGET1): $(TARGET1_OBJS)
	$(CC) $(TARGET1_OBJS) -o $(TARGET1)

$(TARGET2): $(TARGET2_OBJS)
	$(CC) $(TARGET2_OBJS) -o $(TARGET2)

$(BUILDDIR)/$(TARGET1)/%.o: $(SRCDIR)/$(TARGET1)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(BUILDDIR)/$(TARGET2)/%.o: $(SRCDIR)/$(TARGET2)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	$(RM) -r $(BUILDDIR) $(TARGET1) $(TARGET2)

-include $(DEPS)
