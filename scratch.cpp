// Tiny Input Parser.
enum TokenKind {
  TOKEN_EOF,
  TOKEN_NEWLINE,
  TOKEN_INT,
  TOKEN_CHAR,
  TOKEN_STRING,
};

struct Token {
  TokenKind kind;
  char *start;
  char *end;
};

Token next_token(char *stream) {
  switch (*stream) {
  case '\n': {
    return Token{.kind = TOKEN_NEWLINE, .start = stream, .end = ++stream};
  }
  default: {
    assert(0);
    return Token{.kind = TOKEN_EOF, .start = stream, .end = stream};
  }
  }
}

typedef uint32_t u32;
typedef int32_t i32;
typedef uint64_t u64;
typedef int64_t i64;

#define BUF_SIZE 128
char buf[BUF_SIZE];

bool is_u32() {}
bool match_u32() {}
u32 expect_u32() {}

#define BUF_SIZE 128
char buf[BUF_SIZE];

void read_input() {
#ifndef ONLINE_JUDGE
  freopen("a.in", "r", stdin);
#endif
  char *line = fgets(buf, BUF_SIZE, stdin);
}

// There's gotta be a better way for me to parse all this stuff fast.
// Simple lexer and parser functions would probably be useful.