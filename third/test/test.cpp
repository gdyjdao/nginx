#include "test.hpp"

#include <ngx_event.h>
#include <ngx_event_connect.h>
#include <ngx_event_pipe.h>

#include <iostream>
using namespace std;

static ngx_command_t ndg_test_cmds[] = {
	{
		ngx_string("ndg_test"),
		NGX_HTTP_LOC_CONF | NGX_CONF_FLAG,
		ngx_conf_set_flag_slot,
		NGX_HTTP_LOC_CONF_OFFSET,
		offsetof(NdgTestConf, enabled),
		NULL
	},
	ngx_null_command
};

static ngx_int_t init(ngx_conf_t * cf) {
	auto cmcf = reinterpret_cast<ngx_http_core_main_conf_t *>(ngx_http_conf_get_module_main_conf(cf, ngx_http_core_module));

}


static ngx_http_module_t ndg_test_ctx = {
	nullptr,
	init,

};

ngx_module_t ndg_test_module = {
	NGX_MODULE_V1,
	&ndg_test_ctx,
};

static void *create(ngx_conf_t *cf) {
	return nullptr;
}

static ngx_int_t handler(ngx_http_request_t *r) {
	auto cf = reinterpret_cast<NdgTestConf *>(ngx_http_get_module_loc_conf(r, ndg_test_module));
	// ngx_log_error(NGX_LOG_ALERT, cycle->log, 0, "test hello nginx");
	if (cf->enabled) {
		cout << "hello nginx cf->enabled=1";
	}
	else {
		cout << "hello cf->enabled=0" << endl;
	}
	return NGX_DECLINED;
}


