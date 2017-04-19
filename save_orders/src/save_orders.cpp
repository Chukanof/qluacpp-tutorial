#define LUA_LIB
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
  #define LUA_BUILD_AS_DLL
#endif

#include <chrono>
#include <thread>

#include <qlua>

#include "order_db.hpp"

static struct luaL_reg ls_lib[] = {
  { NULL, NULL }
};

void my_main(lua::state& l) {
  using namespace std::chrono_literals;
  qlua::extended_api q(l);
  while (true) {
    std::this_thread::sleep_for(1s);
  }
}

extern "C" {
  LUALIB_API int luaopen_lualib_save_orders(lua_State *L) {
    lua::state l(L);
    qlua::extended_api q(l);

    q.set_callback<qlua::callback::main>(my_main);

    luaL_openlib(L, "lualib_save_orders", ls_lib, 0);
    return 0;
  }
}

