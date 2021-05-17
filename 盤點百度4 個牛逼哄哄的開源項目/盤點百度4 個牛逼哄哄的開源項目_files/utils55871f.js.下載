define("appmsg/comment/comment_write_old.html.js",[],function(){
return'<!-- 旧版写留言 -->\n<div id="js_cmt_mine" class="discuss_container_wrp" style="display:none;">\n  <div class="discuss_container editing access">\n    <div class="discuss_container_inner">\n      <div class="discuss_container_hd">\n        <h2 class="discuss_rich_media_title"><#=textPageTitle#></h2> <!-- 标题要转义 -->\n        <span id="log"></span>\n\n        <div id="js_comment_input_old" class="dicuss_form_area">\n          <!-- 这里放input组件 -->\n        </div>\n      </div>\n      <div class="discuss_container_bd">\n        <!-- 标题 -->\n        <div class="rich_media_extra_title_wrp weui-flex">\n          <div class="weui-flex__item">\n            <strong class="rich_media_extra_title">我的留言</strong>\n          </div>\n        </div>\n\n        <div class="discuss_list_wrp">\n          <ul class="discuss_list" id="js_my_list_old"></ul>\n        </div>\n\n        <!-- 留言加载中 -->\n        <div class="js_mycmt_loading">\n          <div class="weui-loadmore weui-loadmore_default">\n            <i class="weui-loading"></i>\n            <span class="weui-loadmore__tips">正在加载</span>\n          </div>\n        </div>\n      </div>\n    </div>\n  </div>\n</div>\n\n<!-- 秒开下的底部导航条 -->\n<div class="weui-webview-nav" style="display: none;" id="js_fake_bar">\n  <button class="weui-webview-nav__btn_goback" id="js_cmt_goback">goback</button>\n  <button class="weui-webview-nav__btn_forward weui-webview-nav__btn_disabled" disabled="disabled">forward</button>\n</div>\n';
});define("appmsg/comment/comment_write.html.js",[],function(){
return'<# if (!deviceIsPc) { #>\n  <!-- 正在输入discuss_form_area加discuss_form_editing -->\n  <div id="js_cmt_addbtn" class="discuss_form_area weui-flex" style="display: none;">\n    <div id="js_cmt_write" class="weui-flex__item">\n      <div class="discuss_form_input js_cmt_write_placeholder">写下你的留言</div>\n    </div>\n  </div>\n<# } else { #>\n  <!-- pc端文章页留言 -->\n  <div class="comment_primary_area" id="js_comment_pc" style="display: none">\n    <div class="comment_primary_form" id="js_cmt_addbtn_pc">\n      <div class="comment_primary_form_bd comment_primary_input_multiline" id="js_cmt_panel_pc">\n        <div class="comment_primary_input_default" id="js_cmt_input_pc" style="display: none">写下你的留言</div>\n      </div>\n    </div>\n  </div>\n<# } #>';
});define("appmsg/comment/comment_tpl.html.js",[],function(){
return'<!-- 我的留言 -->\n<div class="discuss_container" id="js_my_list_container" style="display: none;">\n  <div class="discuss_list_wrp">\n    <ul class="discuss_list" id="js_my_list"></ul>\n  </div>\n\n  <!-- 留言加载中 -->\n  <div class="js_mycmt_loading">\n    <div class="weui-loadmore weui-loadmore_default">\n      <i class="weui-loading"></i>\n      <span class="weui-loadmore__tips">正在加载</span>\n    </div>\n  </div>\n\n  <!-- 默认收起，展开加weui-fold-tips_unfold -->\n  <div id="js_my_list_folder" class="weui-fold-tips" style="display: none;">展开我的留言</div> <!-- 默认隐藏，如果溢出了再显示 -->\n\n  <div id="js_my_list_footer" style="display: none;"> <!-- 默认隐藏，等我的留言渲染好之后再显示 -->\n    <div class="my_dicuss_list_end_tips weui-loadmore weui-loadmore_default weui-loadmore_line">\n      <span class="weui-loadmore__tips">\n        以上留言被精选后，将对所有人可见      </span>\n    </div>\n  </div>\n</div>\n\n<!-- 精选留言 -->\n<div class="discuss_container" id="js_cmt_main" style="display: none;">\n  <div class="rich_media_extra_title_wrp weui-flex">\n    <div class="weui-flex__item">\n      <strong class="rich_media_extra_title">精选留言</strong>\n    </div>\n    <# if (!isWxWork) { #>\n      <p class="tips_global" id="js_cmt_nofans1" style="display: none;">作者已设置关注后才可以留言</p>\n    <# } #>\n  </div>\n  <div class="discuss_list_wrp">\n    <ul class="discuss_list" id="js_cmt_list"></ul>\n  </div>\n</div>\n\n<# if (!isWxWork) { #>\n  <div class="discuss_container" id="js_cmt_nofans2" style="display: none;">\n    <div class="tips_global tc" id="js_cmt_nofans2_inner">\n      作者已设置关注后才可以留言    </div>\n  </div>\n<# } #>\n\n<div id="js_cmt_loading">\n  <div class="weui-loadmore weui-loadmore_default">\n    <i class="weui-loading"></i>\n    <span class="weui-loadmore__tips">正在加载</span>\n  </div>\n</div>\n\n<div id="js_cmt_statement" style="display: none;">\n  <div class="weui-loadmore weui-loadmore_default weui-loadmore_line weui-loadmore_dot">\n    <span class="weui-loadmore__tips"></span>\n  </div>\n</div>\n\n<!-- warning toast -->\n<div class="discuss_warn_toast weui-toast__wrp" id="js_warning_toast" style="display: none;">\n  <div class="weui-mask_transparent"></div>\n  <div class="weui-toast weui-toast_text-more">\n    <i class="weui-icon-warn weui-icon_toast"></i>\n    <p class="weui-toast__content js_content"></p>\n  </div>\n</div>\n';
});define("biz_wap/utils/fakehash.js",["biz_common/dom/event.js"],function(t){
"use strict";
function s(t){
t=t||location.hash.substr(1);
var s,o,e,i,r=!1,c=[];
for(s=0;s<h.length;s++)o=h[s],e=o[0],i=o[1],e!==a?("string"==typeof e&&e===t||e instanceof RegExp&&e.test(t))&&(i(n),
r=!0):c.push(i);
if(!r)for(s=0;s<c.length;s++)c[s](n,t);
n=t;
}
var o=t("biz_common/dom/event.js"),h=[],a="__default_hash__",n=location.hash.substr(1);
return o.on(window,"popstate",function(t){
var o=a;
t.state&&t.state.hash&&(o=t.state.hash),s(o);
}),o.on(window,"hashchange",s),o.on(window,"load",function(){
history.state&&history.state.hash&&s(history.state.hash);
}),{
val:function(){
return history.state&&history.state.hash||location.hash.substr(1);
},
push:function(t){
history.pushState?(history.pushState({
hash:t
},document.title,location.href),s(t)):location.hash=t;
},
replace:function(t){
history.replaceState?(history.replaceState({
hash:t
},document.title,location.href),s(t)):this.push(t);
},
on:function(t,s){
"function"==typeof t&&(s=t,t=a),h.push([t,s]);
}
};
});define("appmsg/comment_report.js",["biz_wap/utils/ajax.js","biz_common/dom/event.js","biz_wap/utils/storage.js","common/utils.js","biz_common/dom/offset.js"],function(e){
"use strict";
function t(){
if(!n&&(n=!0,setTimeout(function(){
n=!1;
},20),o||(o=document.getElementById("js_cmt_area")))){
var e=c.getInnerHeight(),t=window.pageYOffset||document.documentElement.scrollTop||document.body.scrollTop,i=o.querySelectorAll(".js_comment_item");
if(m=p.getOffset(o).offsetTop,i.length)for(var s=0;s<i.length&&m+i[s].offsetTop<t+e;s++)1!=i[s].getAttribute("data-hasreport")&&(i[s].setAttribute("data-hasreport",1),
_.data.push({
content_id:i[s].dataset.content_id,
is_elected_comment:1,
is_friend_comment:1*i[s].dataset.friend,
scene:1
}));
d.set("comment_expose",_,Date.now()+6048e5);
}
}
var o,m,n,i=e("biz_wap/utils/ajax.js"),s=e("biz_common/dom/event.js"),a=e("biz_wap/utils/storage.js"),c=e("common/utils.js"),d=new a("comment_expose"),p=e("biz_common/dom/offset.js"),_={
data:[],
appmsgid:"",
comment_id:"",
idx:"",
item_show_type:0,
biz:""
},r=function(e){
e&&e.data&&e.data.length&&(u(e),d.remove("comment_expose"));
},u=function(e){
i({
type:"post",
url:"/mp/appmsg_comment?action=exposurecomment",
data:{
comment_id:e.comment_id,
appmsgid:e.appmsgid,
idx:e.idx,
item_show_type:e.item_show_type,
__biz:e.biz,
data:JSON.stringify(e.data)
},
async:!1,
timeout:2e3
});
};
s.on(window,"scroll",t),s.on(window,"unload",function(){
r(_);
}),s.on(window,"load",function(){
var e=d.getData("comment_expose");
e&&e.comment_expose&&e.comment_expose.val&&e.comment_expose.val.appmsgid&&r(e.comment_expose.val),
t();
});
var f=function(e){
_.comment_id=e.comment_id,_.appmsgid=e.appmsgid,_.idx=e.idx,_.item_show_type=e.item_show_type||0,
_.biz=e.biz,setTimeout(function(){
t();
});
};
return f;
});define("appmsg/retry_ajax.js",["biz_wap/utils/ajax.js","biz_wap/jsapi/core.js"],function(require,exports,module,alert){
"use strict";
function Retry_ajax(e){
checkAjaxDo(e),e&&(e.success=function(a){
dealWithSucceed(a,e);
},e.error=function(){
dealWithFailed(e);
}),ajax(e);
}
function checkAjaxDo(e){
var a=isContainExceptLike(e,failedQueue),i=isContainAjax(e,failedQueue);
-1===i&&a>-1&&failedQueue.splice(a,1);
}
function isContainExceptLike(e,a){
var i=-1;
for(var r in a){
var t=a[r];
if(e.url||-1!=e.url.indexOf("&like=")||-1!=t.url.indexOf("&like=")){
if(!(e.url.indexOf("&like=")>-1&&t.url.indexOf("&like=")>-1))continue;
if(removeLikeParam(e.url)!==removeLikeParam(t.url))continue;
}else if(!t.url||t.url!==e.url)continue;
if(e.data&&t.data){
var u=e.data,n=t.data;
if(!isEqualExceptLike(u,n))continue;
}
i=r;
break;
}
return i;
}
function isContainAjax(e,a){
var i=-1;
for(var r in a){
var t=a[r];
if(e.url&&t.url&&e.url==t.url){
if(e.data&&t.data){
var u=e.data,n=t.data;
if(!isEqual(u,n))continue;
}
i=r;
break;
}
}
return i;
}
function removeLikeParam(e){
var a=e.indexOf("&like="),i=e.substring(0,a)+e.substring(a+7);
return i;
}
function isEqualExceptLike(e,a){
var i=Object.getOwnPropertyNames(e),r=Object.getOwnPropertyNames(a);
if(i.length!=r.length)return!1;
for(var t=0;t<i.length;t++){
var u=i[t];
if("like"!==u&&e[u]!==a[u])return!1;
}
return!0;
}
function isEqual(e,a){
var i=Object.getOwnPropertyNames(e),r=Object.getOwnPropertyNames(a);
if(i.length!=r.length)return!1;
for(var t=0;t<i.length;t++){
var u=i[t];
if(e[u]!==a[u])return!1;
}
return!0;
}
function dealWithSucceed(res,obj){
try{
var data=eval("("+res+")");
}catch(e){
var data=!1;
}
if(data&&data.base_resp&&0===data.base_resp.ret){
var findIndex=isContainExceptLike(obj,failedQueue);
findIndex>-1&&failedQueue.splice(findIndex,1);
}else dealWithFailed(obj);
}
function dealWithFailed(e){
var a=isContainExceptLike(e,failedQueue);
if(-1===a){
if(e.failedTimes=1,failedQueue.length>=MAX_QUEUE_LEN)return;
failedQueue.push(e);
}else{
var i=isContainAjax(e,failedQueue);
if(i>-1){
if(failedQueue[a].failedTimes++,e.failedTimes=failedQueue[a].failedTimes,e.failedTimes>MAX_FAILED_TIMES)return void failedQueue.splice(i,1);
}else failedQueue.splice(i,1),e.failedTimes=1,failedQueue.push(e);
}
Retry_ajax(e);
}
var ajax=require("biz_wap/utils/ajax.js"),JSAPI=require("biz_wap/jsapi/core.js"),failedQueue=[],MAX_FAILED_TIMES=2,MAX_QUEUE_LEN=20;
return Retry_ajax;
});define("complain/tips.js",["biz_common/utils/string/html.js","biz_common/dom/event.js"],function(t){
"use strict";
t("biz_common/utils/string/html.js");
var i=t("biz_common/dom/event.js"),o={
tipsTimeoutId:null,
tipsDom:document.getElementById("tips")
},s={
showErrTips:function(t,i){
var s=i||o.tipsDom;
return t===!1?void(s.style.display="none"):(this.resetTips(),s.innerHTML=t.htmlEncode(),
s.style.display="block",clearTimeout(o.tipsTimeoutId),void(o.tipsTimeoutId=setTimeout(function(){
s.style.display="none";
},4e3)));
},
resetTips:function(t){
setTimeout(function(){
var i=t||o.tipsDom;
i&&(i.style.top=document.body.scrollTop+"px");
},0);
}
};
return i.on(window,"scroll",function(){
s.resetTips();
}),s;
});define("pages/loadscript.js",[],function(){
"use strict";
function e(t){
e.counter||(e.counter=1);
var n="number"!=typeof t.retry?1:t.retry,o=t.win||window,r=o.document,a=r.createElement("script"),i=t.type||"JSONP",d=r.head||r.getElementsByTagName("head")[0]||r.documentElement,l=t.callbackName,c="uninitialized",u="undefined"==typeof t.successCode?200:t.successCode,s="undefined"==typeof t.timeoutCode?500:t.timeoutCode,f="undefined"==typeof t.scriptErrorCode?400:t.scriptErrorCode,m=!1,p=null;
"JSONP"!=i&&"JS"!=i&&(i="JSONP");
var y="";
y="JSONP"==i?t.url+"&t="+Math.random():t.url;
var h=function(e){
a&&!m&&(m=!0,p&&(clearTimeout(p),p=null),a.onload=a.onreadystatechange=a.onerror=null,
d&&a.parentNode&&d.removeChild(a),a=null,l&&-1==l.indexOf(".")&&(window[l]=null),
"JS"==i&&e==u&&"loaded"==c&&"function"==typeof t.callback?t.callback():e!=u&&"loaded"!=c&&"function"==typeof t.onerror&&t.onerror(e));
};
if(l&&"function"==typeof t.callback&&"JSONP"==i){
var w=l;
-1==l.indexOf(".")&&(l=window[l]?l+e.counter++:l,window[l]=function(){
c="loaded",t.callback.apply(null,arguments);
}),y=y.replace("="+w,"="+l);
}
a.onload=a.onreadystatechange=function(){
var e=navigator.userAgent.toLowerCase();
(-1!=e.indexOf("opera")||-1==e.indexOf("msie")||/loaded|complete/i.test(this.readyState))&&("JS"==i&&(c="loaded"),
h("loaded"==c?u:f));
},a.onerror=function(){
return n>0?(t.retry=n-1,p&&(clearTimeout(p),p=null),void e(t)):void h(f);
},t.timeout&&(p=setTimeout(function(){
h(s);
},parseInt(t.timeout,10))),c="loading",a.charset="utf-8",setTimeout(function(){
a.src=y;
try{
d.insertBefore(a,d.lastChild);
}catch(e){}
},0);
}
return e;
});define("biz_wap/utils/ajax_load_js.js",["biz_wap/utils/ajax.js","biz_wap/utils/localstorage.js"],function(e){
"use strict";
function n(e){
var n=d(e.url,e.version),o=function(){},i=function(){};
if("function"==typeof e.onSuccess&&(o=e.onSuccess),"function"==typeof e.onError&&(i=e.onError),
c(e.win,n))return void o({
code:1,
queueIndex:0
});
if(e.useCache){
var a=u(e.url,e.version);
if(a&&t({
win:e.win,
funcStr:a,
useCache:!1,
url:e.url,
version:e.version
}),c(e.win,n))return void o({
code:2,
queueIndex:0
});
}
if(S.callbackQueue.push({
options:e,
onSuccess:o,
onError:i
}),"undefined"==typeof S.jsLoadState[n]&&(S.jsLoadState[n]=-1),-1==S.jsLoadState[n]){
var s=e.url;
s+=-1==s.indexOf("?")?"?"+S.customerParam+"="+e.version:"&"+S.customerParam+"="+e.version,
r({
originUrl:e.url,
version:e.version,
url:s,
key:n
});
}
}
function r(e){
S.jsLoadState[e.key]=1,w({
url:e.url,
notJoinUrl:!0,
timeout:1e4,
type:"POST",
dataType:"text",
noXRequestedWidthHeader:!0,
success:function(n){
if(1==S.jsLoadState[e.key]){
S.jsLoadState[e.key]=-1;
var r=!0;
r=n?t({
win:null,
funcStr:n,
useCache:!0,
url:e.originUrl,
version:e.version
}):!1,o(r?{
code:3,
type:"suc",
funcStr:n
}:{
code:51,
type:"err"
});
}
},
error:function(){
1==S.jsLoadState[e.key]&&(S.jsLoadState[e.key]=-1,o({
code:52,
type:"err"
}));
},
complete:function(){
1==S.jsLoadState[e.key]&&(S.jsLoadState[e.key]=-1,o({
code:53,
type:"err"
}));
}
});
}
function t(e){
var n=e.win||window,r=!0;
try{
n.eval(e.funcStr),r=!0;
}catch(t){
r=!1;
}
return r?(s({
url:e.url,
version:e.version,
win:n
}),e.useCache&&a(e.url,e.version,e.funcStr),!0):(l({
url:e.url,
version:e.version,
win:n
}),i(e.url),!1);
}
function o(e){
for(var n=0,r=S.callbackQueue.length;r>n;n++){
var o=S.callbackQueue[n],u=o.options,i=u.win,a=d(u.url,u.version);
"suc"==e.type?(e.funcStr&&!c(i,a)&&t({
win:i,
funcStr:e.funcStr,
useCache:!1,
url:u.url,
version:u.version
}),o.onSuccess({
code:e.code,
queueIndex:n
})):o.onError({
code:e.code,
queueIndex:n
});
}
S.callbackQueue=[];
}
function u(e,n){
var r=f(e),t=y.get(r);
if(!t)return null;
var o;
try{
o=JSON.parse(t);
}catch(u){}
if(o){
var a=+new Date,c=1*o.time;
return a-c>S.lsTimeout||o.version!=n||!o.func?(i(e),null):o.func;
}
}
function i(e){
var n=f(e);
y.remove(n);
}
function a(e,n,r){
var t={
version:n,
func:r,
time:+new Date
},o=f(e);
try{
y.set(o,JSON.stringify(t));
}catch(u){}
}
function c(e,n){
return e=e||window,e[S.winCacheKey]&&e[S.winCacheKey][n]&&e[S.winCacheKey][n].state===!0?!0:!1;
}
function s(e){
var n=d(e.url,e.version),r=e.win||window;
r[S.winCacheKey]||(r[S.winCacheKey]={}),r[S.winCacheKey][n]||(r[S.winCacheKey][n]={}),
r[S.winCacheKey][n].state=!0;
}
function l(e){
var n=d(e.url,e.version),r=e.win||window;
if(r[S.winCacheKey]&&r[S.winCacheKey][n])try{
delete r[S.winCacheKey][n];
}catch(t){}
}
function f(e){
return encodeURIComponent(e);
}
function d(e,n){
return encodeURIComponent(e)+"_"+n||"";
}
function v(e){
l(e),i(e.url);
}
var w=e("biz_wap/utils/ajax.js"),y=e("biz_wap/utils/localstorage.js"),S={
jsLoadState:{},
winCacheKey:"__loadExternalJsStates__",
lsTimeout:1728e5,
customerParam:"wxv",
callbackQueue:[]
};
return{
ClearCache:v,
Load:n
};
});function _typeof(e){
return e&&"undefined"!=typeof Symbol&&e.constructor===Symbol?"symbol":typeof e;
}
var _extends=Object.assign||function(e){
for(var t=1;t<arguments.length;t++){
var n=arguments[t];
for(var r in n)Object.prototype.hasOwnProperty.call(n,r)&&(e[r]=n[r]);
}
return e;
};
define("appmsg/reward_entry.js",["biz_wap/ui/weui.js","biz_common/dom/event.js","biz_wap/utils/ajax.js","biz_wap/jsapi/core.js","biz_wap/utils/mmversion.js","appmsg/appmsgext.js","appmsg/open_url_with_webview.js","common/utils.js","biz_wap/utils/device.js","appmsg/loading.js","common/comm_report.js","appmsg/pay_read_utils.js","biz_wap/utils/jsmonitor_report.js"],function(e,t,n,r){
"use strict";
function a(e){
e&&(e.style.display="block");
}
function i(e){
e&&(e.style.display="none");
}
function d(e){
v.getData({
biz:biz,
appmsg_type:appmsg_type,
mid:mid,
sn:sn,
idx:idx,
pass_ticket:window.pass_ticket,
scene:E.scene,
title:E.title,
ct:ct,
devicetype:E.devicetype,
version:E.version,
is_need_reward:E.is_need_reward,
reward_uin_count:E.is_need_reward?3*p:0,
send_time:E.send_time||"",
item_show_type:window.item_show_type||"",
rtId:E.appmsgextRtId,
rtKey:E.appmsgextRtKey,
is_pay_subscribe:window.isPaySubscribe,
pay_subscribe_uin_count:window.isPaySubscribe?3*k.getCountPerLine():0,
onSuccess:function(t){
t&&(e||(L.rewardLink&&m.off(L.rewardLink,"click",O),L.authorAvatarLink&&m.off(L.authorAvatarLink,"click",P),
A=[],o({
reward_total:t.reward_total_count,
reward_head_imgs:t.reward_head_imgs||[],
can_reward:t.can_reward,
timestamp:t.timestamp,
reward_author_head:t.reward_author_head,
rewardsn:t.rewardsn,
can_whisper:t.can_whisper
})),console.log("reloadRewardData:",t,e),k.init(t.pay_subscribe_info,{
rewardTotal:t.reward_total_count,
rewardTotalCut:t.is_reward_total_count_cut
},!0));
},
onError:function(){}
});
}
function s(e,t,n){
if("link"===n){
var a="#wechat_redirect";
e=e.replace(a,"&__tc=1"+a);
}
var i=function(){
N.src=t+"&qrcode_timestamp="+1*new Date+"#wechat_redirect";
},d=null;
return function(t){
if(t.preventDefault(),"link"===n&&E.is_teenager)return weui.alert("青少年模式下不可赞赏"),
void T.setSum(232209,0,1);
if("0"==E.user_can_reward)return void r("你已成为该公众号的黑名单用户，暂时无法赞赏。");
if(E.isWindowsWechat){
var a=function(){
var e="js_author_reward_qrcode",t="reward_pop_show",n=document.getElementById(e);
if(n.classList.contains(t))return{
v:void 0
};
i(),d=setInterval(i,12e4),n.classList[L.rewardLink.getBoundingClientRect().top<222?"add":"remove"]("reward_pop_bottom"),
n.classList.add(t);
var r=function a(r){
if(n.classList.contains(t)){
for(var i=r.target;null!==i&&i.id!==e;)i=i.parentNode;
(null===i||i.id!==e)&&(n.classList.remove(t),clearInterval(d),d=null,m.off(window,"click",a));
}
};
setTimeout(function(){
m.on(window,"click",r);
},1);
}();
if("object"===("undefined"==typeof a?"undefined":_typeof(a)))return a.v;
}else"avatar"===n&&window.__addIdKeyReport?window.__addIdKeyReport(E.likeHeadId,E.likeHeadKey):window.__addIdKeyReport&&window.__addIdKeyReport(E.likeBtnId,E.likeBtnKey),
f.invoke("openUrlWithExtraWebview",{
url:e,
openType:1
},function(t){
t.err_msg.indexOf(":ok")>-1||(location.href=e);
});
};
}
function o(e){
var t=window.innerWidth||document.documentElement.innerWidth,n=(Math.ceil((b.getInnerHeight()-188)/42)+1)*Math.floor((t-15)/42);
_="http://mp.weixin.qq.com/mp/reward?act=getrewardheads&__biz="+biz+"&appmsgid="+mid+"&idx="+idx+"&sn="+sn+"&offset=0&count="+n+"&source=1#wechat_redirect";
var r="#wechat_redirect",o="";
o="https://mp.weixin.qq.com/mp/author?action=show&__biz="+biz+"&appmsgid="+mid+"&timestamp="+e.timestamp+"&author_id="+E.author_id+"&idx="+idx+"&scene="+E.authorPageScene+"&rscene="+E.authorPageRscene+"&from_scene="+window.source+"&from_subscene="+window.subscene+"&from_enterid="+window.enterid+"&from_sessionid="+window.sessionid+"&is_fans="+e.isFans,
e.rewardsn&&(o+="&rewardsn="+e.rewardsn),o+=r,-1==navigator.userAgent.indexOf("Android")||E.author_id||(o="https://mp.weixin.qq.com/bizmall/reward?act=showpage&__biz="+biz+"&appmsgid="+mid+"&idx="+idx+"&sn="+sn+"&timestamp="+e.timestamp+"&showwxpaytitle=1&rewardsn="+e.rewardsn+r);
var u=L.rewardLink,v=L.authorAvatarLink;
if(!U&&b.listenStateChange({
cb:function(e){
if("onResume"==e.state_change||"onResume"==e.state)if(u){
var t=(new Date).valueOf();
if(-1!=navigator.userAgent.indexOf("Android")&&localStorage.getItem("lastOnresumeTime")&&t-parseInt(localStorage.getItem("lastOnresumeTime"))<=S)return;
localStorage.setItem("lastOnresumeTime",t),g.isAndroid&&!E.author_id&&f.invoke("setNavigationBarColor",{
actionCode:"1"
}),d();
}else d(!0);
}
}),U=!0,u){
var x="/mp/authorreward?action=getqrcode&author_id="+E.author_id+"&rewardsn="+e.rewardsn+"&timestamp="+e.timestamp+"&__biz="+biz+"&appmsgid="+mid+"&idx="+idx+"&size=160";
if(O=s(o,x,"link"),P=s(o,x,"avatar"),m.on(u,"click",O),E.author_id&&1==e.can_reward&&v&&m.on(v,"click",P),
1==e.can_reward&&E.author_id&&L.reward){
a(document.getElementById("js_reward_author")),a(L.authorAvatarLink),L.rewardAuthorHead&&L.rewardAuthorHead.setAttribute("src",e.reward_author_head),
L.reward.classList.add("reward_area_primary");
var I=L.rewardLinkText;
I&&(I.innerText="喜欢作者",Math.random()<.05?I.innerText="稀罕作者":Math.random()>.05&&Math.random()<.1&&(I.innerText="钟意作者")),
L.rewardTotalText&&(L.rewardTotalText.innerText="人喜欢"),E.isWindowsWechat&&L.reward.classList.add("reward_area_win"),
!b.isNativePage()&&e.can_whisper?q():F();
}
}
B=e.reward_head_imgs;
var j=c();
L.reward&&(E.author_id||g.isAndroid)&&1==e.can_reward?(a(L.reward),m.on(window,"load",function(){
l&&(m.off(window,"scroll",l),m.on(window,"scroll",l));
})):i(L.reward);
var k=document.getElementById("js_reward_inner");
!window.isPaySubscribe&&k&&j>0&&a(k);
var T=[].concat(B),M=document.getElementById("js_reward_total");
if(H=16*p,A=[].concat(B),M)if(M.innerText=e.reward_total,E.isWindowsWechat){
var R=M.parentNode;
R.dataset.hasEvent||!function(){
var t=document.getElementById("js_reward_pagination"),n=t.getElementsByClassName("js_reward_pagination_curpage")[0],r=Math.ceil(e.reward_total/H),d=1,s=!0,o=document.getElementById("js_reward_list"),c=function(t,n){
for(var a=(t-1)*H,i=s?3*p:0,d=document.createDocumentFragment(),c=a+i,l=t===r?e.reward_total:t*H;l>c;c++)w(d,n?window.defaultAvatarUrl:A[c]);
return!s&&(o.innerHTML=""),o.appendChild(d),s=!1,n?function(){
for(var e=o.getElementsByClassName("reward_user_avatar"),t=i,n=e.length;n>t;t++)e[t].firstElementChild.src=A[a+t];
}:!1;
};
n.innerHTML=d,t.getElementsByClassName("js_reward_pagination_totalpage")[0].innerHTML=r;
var l="/mp/reward?act=getrewardheads&__biz="+biz+"&appmsgid="+mid+"&idx="+idx+"&sn="+sn+"&count="+H,u=null,_=function(t){
var n=A.length;
e.reward_total>n&&t*H>n?(u=null,u=c(t,!0),h({
url:l+"&offset="+(t-1)*H+"#wechat_redirect",
type:"GET",
success:function(e){
try{
e=JSON.parse(e),e.reward_heads=JSON.parse(e.reward_heads).reward_heads;
}catch(t){
e={};
}
e.base_resp&&0===e.base_resp.ret&&(e.reward_heads.forEach(function(e){
var t=T.indexOf(e);
t>-1?T.splice(t,1):A.push(e);
}),"function"==typeof u&&u());
}
})):c(t);
};
j<e.reward_total&&!function(){
L.reward.classList.add("reward_avatar_overflow");
for(var w=o.children[0];1!==w.nodeType;)w=reward.nextElementSibling;
var c=getComputedStyle(w),l=w.offsetHeight+parseInt(c.marginBottom)+parseInt(c.marginTop);
z=function(t){
o.style.height="fold"===t?3*l+"px":r>d?l*Math.ceil(H/p)+"px":l*Math.ceil(e.reward_total%H/p)+"px";
},z("fold"),m.on(R,"click",function(){
L.reward.classList.contains("reward_avatar_unfold")?(L.reward.classList.remove("reward_avatar_unfold"),
r>1&&i(t),z("fold")):(1===d&&s&&_(d),L.reward.classList.add("reward_avatar_unfold"),
r>1&&a(t),z("unfold"));
}),r>1&&m.on(t,"click",function(e){
var t=e.target;
if(t.classList.contains("js_reward_pagination_prev")){
if(d--,n.innerHTML=d,_(d),1===d&&(t.disabled=!0),d===r-1){
for(;t&&!t.classList.contains("js_reward_pagination_next");)t=t.nextElementSibling;
t&&(t.disabled=!1),z("unfold");
}
}else if(t.classList.contains("js_reward_pagination_next")&&(d++,n.innerHTML=d,_(d),
d===r&&(t.disabled=!0,z("unfold")),2===d)){
for(;t&&!t.classList.contains("js_reward_pagination_prev");)t=t.previousElementSibling;
t&&(t.disabled=!1);
}
});
}(),R.dataset.hasEvent=1;
}();
}else M.setAttribute("data-href",_),M.getAttribute("data-hasevent")||(m.on(M,"click",function(){
var e=M.getAttribute("data-href");
return y(e,{
sample:1,
reject:function(){
location.href=e;
}
}),!1;
}),M.setAttribute("data-hasevent",1));
}
function w(e,t){
var n=document.createElement("span");
n.className="reward_user_avatar";
var r=new Image;
return r.onload=function(){
window.logs&&window.logs.reward_heads_total++,r.onload=r.onerror=null;
},r.onerror=function(){
window.logs&&window.logs.reward_heads_total++,window.logs&&window.logs.reward_heads_fail++,
r.onload=r.onerror=null;
},r.src=t,n.appendChild(r),e.appendChild(n),n;
}
function c(e){
var t=A.length?A:B;
if(t.length){
var n=document.getElementById("js_reward_list"),r=0,a=document.createDocumentFragment();
if(n){
var i=L.reward.classList.contains("reward_avatar_unfold");
if("function"==typeof z&&z(i?"unfold":"fold"),!e){
for(var d=0,s=t.length;s>d&&(r++,w(a,t[d]),i||r!==3*p)&&r!==(H||16*p);++d);
r>p&&(n.className+=" tl"),n.innerHTML="",n.appendChild(a);
}
}
return r;
}
}
function l(){
if(L.reward){
var e=window.pageYOffset||document.documentElement.scrollTop;
if(e+b.getInnerHeight()>L.reward.offsetTop){
var t="__biz="+biz+"&appmsgid="+mid+"&idx="+idx+"&item_show_type="+item_show_type;
window.cgiData&&window.cgiData.vid&&(t+="&vid="+cgiData.vid),h({
type:"GET",
url:"/bizmall/reward?act=report&"+t,
async:!0
}),m.off(window,"scroll",l),l=null;
}
}
}
function u(e){
"undefined"!=typeof e.scene&&(E.scene=e.scene),"undefined"!=typeof e.is_need_reward&&(E.is_need_reward=e.is_need_reward),
"undefined"!=typeof e.title&&(E.title=e.title),"undefined"!=typeof e.author_id&&(E.author_id=e.author_id),
"undefined"!=typeof e.user_can_reward&&(E.user_can_reward=e.user_can_reward),"undefined"!=typeof e.appmsgextRtId&&(E.appmsgextRtId=e.appmsgextRtId),
"undefined"!=typeof e.appmsgextRtKey&&(E.appmsgextRtKey=e.appmsgextRtKey),"undefined"!=typeof e.likeHeadId&&(E.likeHeadId=e.likeHeadId),
"undefined"!=typeof e.likeHeadKey&&(E.likeHeadKey=e.likeHeadKey),"undefined"!=typeof e.likeBtnId&&(E.likeBtnId=e.likeBtnId),
"undefined"!=typeof e.likeBtnKey&&(E.likeBtnKey=e.likeBtnKey),"undefined"!=typeof e.authorPageScene&&(E.authorPageScene=e.authorPageScene),
"undefined"!=typeof e.authorPageRscene&&(E.authorPageRscene=e.authorPageRscene),
"undefined"!=typeof e.devicetype&&(E.devicetype=e.devicetype),"undefined"!=typeof e.version&&(E.version=e.version),
"undefined"!=typeof e.send_time&&(E.send_time=e.send_time);
}
e("biz_wap/ui/weui.js");
var p,_,m=e("biz_common/dom/event.js"),h=e("biz_wap/utils/ajax.js"),f=e("biz_wap/jsapi/core.js"),g=e("biz_wap/utils/mmversion.js"),v=e("appmsg/appmsgext.js"),y=e("appmsg/open_url_with_webview.js"),b=e("common/utils.js"),x=e("biz_wap/utils/device.js"),I=e("appmsg/loading.js"),j=e("common/comm_report.js"),k=e("appmsg/pay_read_utils.js"),T=e("biz_wap/utils/jsmonitor_report.js"),E={
scene:window.source||"",
is_need_reward:!1,
is_teenager:window.is_teenager,
title:window.msg_title||"",
author_id:window.author_id||"",
user_can_reward:!0,
appmsgextRtId:"",
appmsgextRtKey:"",
likeHeadId:"110809",
likeHeadKey:"2",
likeBtnId:"110809",
likeBtnKey:"3",
authorPageScene:"142",
authorPageRscene:"128",
devicetype:window.devicetype||"",
version:window.version||"",
send_time:window.send_time||"",
isWindowsWechat:-1!==window.navigator.userAgent.indexOf("WindowsWechat"),
whisperMaxLen:40,
focusTag:!1,
doubleInputChar:["“”","‘’","（）","《》","〈〉","「」","『』","〔〕","【】","［］","[]","｛｝","{}","()","<>"],
sendLock:!1
},L={
reward:document.getElementById("js_reward_area"),
rewardLink:document.getElementById("js_reward_link"),
authorAvatarLink:document.getElementById("js_reward_avatar"),
rewardAuthorHead:document.getElementById("js_reward_author_head"),
rewardLinkText:document.getElementById("js_reward_link_text"),
rewardTotalText:document.getElementById("js_reward_total_text"),
whisperWrap:document.getElementById("js_reward_whisper"),
whisperDialogShow:document.getElementById("js_show_whisper_dialog"),
whisperDialogHide:document.getElementById("js_hide_whisper_dialog"),
whisperDialogMask:document.getElementById("js_whisper_dialog_mask"),
whisperDialog:document.getElementById("js_reward_whisper_dialog"),
whisperTextarea:document.getElementById("js_whisper_text"),
whisperMsg:document.getElementById("js_whisper_msg"),
whisperCnt:document.getElementById("js_whisper_current_cnt"),
whisperSend:document.getElementById("js_whisper_send")
},B=[],S=500,z=null,H=0,A=[];
window.logs&&(window.logs.reward_heads_total=0,window.logs.reward_heads_fail=0);
var M,R=function(e){
var t=e.target;
"TEXTAREA"!==t.tagName&&"BUTTON"!==t.tagName&&(e.preventDefault(),e.stopPropagation());
},D=function(e){
var t=e.targetTouches||[];
if(t.length>0){
var n=t[0]||{};
M=n.clientY;
}
},K=function(e){
var t=!1,n=e.changedTouches,r=this.scrollTop,a=this.offsetHeight,i=this.scrollHeight;
if(n.length>0){
var d=n[0]||{},s=d.clientY;
t=s>M&&0>=r?!1:M>s&&r+a>=i?!1:!0,t||e.preventDefault();
}
},W=function(){
document.addEventListener("touchmove",R,{
passive:!1
}),L.whisperTextarea.addEventListener("touchstart",D,{
passive:!1
}),L.whisperTextarea.addEventListener("touchmove",K,!1);
},C=function(){
document.removeEventListener("touchmove",R,{
passive:!1
}),L.whisperTextarea.removeEventListener("touchstart",D,{
passive:!1
}),L.whisperTextarea.removeEventListener("touchmove",K,!1);
},O=function(){},P=function(){},N=document.getElementById("js_author_reward_qrcode_img"),q=function(){
return a(L.whisperWrap);
},F=function(){
return i(L.whisperWrap);
},U=!1,J=function(e){
var t=0;
try{
t=1*window.atob(window.biz);
}catch(n){}
var r={
BizUin:t,
BizUinStr:window.biz||"",
AppMsgId:window.parseInt(window.mid,10)||0,
ItemIdx:window.parseInt(window.idx,10)||0,
ItemShowType:window.parseInt(window.item_show_type,10)||0,
SessionIdStr:window.sessionid||"",
EnterId:window.parseInt(window.enterid,10)||0,
Scene:window.parseInt(window.source,10)||0,
SubScene:window.parseInt(window.subscene,10)||0,
IsFans:1*e||0
},d=function(e){
return weui.alert(e&&e>E.whisperMaxLen?"悄悄话不可以超过字":"网络异常，请稍后重试");
},s=function(){
if(!L.whisperSend.disabled&&!E.sendLock){
E.sendLock=!0,j.report(19048,_extends({
EventType:3
},r)),I.show("发送中");
var e=L.whisperTextarea.value.replace(/^\s+|\s+$/g,"");
h({
url:"/mp/author?action=whisper",
data:{
__biz:window.biz||window.__biz,
mid:window.mid||window.appmsgid,
idx:window.idx,
content:e,
scene:window.source,
subscene:window.subscene,
enterid:window.enterid,
sessionid:window.sessionid
},
type:"POST",
success:function(t){
try{
t=JSON.parse(t);
}catch(n){
t={};
}
E.sendLock=!1,I.hide(),t&&t.base_resp&&0===t.base_resp.ret?(o(),F(),weui.toast("已发送",1e3)):d(e.length);
},
error:function(){
E.sendLock=!1,I.hide(),d();
}
});
}
},o=function(){
i(L.whisperDialog),L.whisperTextarea.value="",L.whisperSend.disabled=!0,C();
};
m.on(L.whisperDialogShow,"click",function(){
j.report(19048,_extends({
EventType:2
},r)),a(L.whisperDialog),L.whisperTextarea.focus(),W();
}),m.on(L.whisperDialogHide,"mousedown",o),m.on(L.whisperDialogMask,"mousedown",o),
m.on(L.whisperTextarea,"input",function(e){
var t=e.target.value.replace(/^\s+|\s+$/g,"").length;
t>E.whisperMaxLen?(L.whisperSend.disabled=!0,L.whisperCnt.innerHTML=t,L.whisperMsg.style.visibility="visible"):(L.whisperSend.disabled=0===t,
L.whisperMsg.style.visibility="hidden"),x.os.ios&&e.data&&E.doubleInputChar.indexOf(e.data)>-1&&(E.focusTag=!0);
}),m.on(L.whisperTextarea,"click",function(e){
if(x.os.ios&&E.focusTag){
var t=e.target;
t.blur(),t.focus(),E.focusTag=!1;
}
}),m.on(L.whisperSend,"mousedown",s);
};
return{
handle:function(e,t){
p=t,u(e),1==e.can_reward&&E.author_id&&L.reward&&J(e.isFans),o(e);
},
render:function(e){
p=e,c(!0);
},
bindWhisperEvent:J,
showWhisperWrap:q
};
});define("pages/scrollY.js",["pages/utils.js"],function(n){
"use strict";
var e=n("pages/utils.js"),t=window.requestAnimationFrame,o=0;
["webkit","moz","ms","o"].some(function(n){
return t?!0:(t=t||window[n+"RequestAnimationFrame"],!1);
}),t||(t=function(n){
var e=(new Date).getTime(),t=Math.max(0,16-(e-o));
return o=e+t,window.setTimeout(function(){
return n(e+t);
},t);
});
var i={
easeOutSine:function(n){
return Math.sin(n*(Math.PI/2));
},
easeInOutSine:function(n){
return-.5*(Math.cos(Math.PI*n)-1);
},
easeInOutQuint:function(n){
return n/=.5,1>n?.5*Math.pow(n,5):.5*(Math.pow(n-2,5)+2);
},
easeInOutCubic:function(n){
return.5>n?4*n*n*n:(n-1)*(2*n-2)*(2*n-2)+1;
}
},r=function(n,e,t){
"function"==typeof n&&n(),void 0===t?(document.documentElement.scrollTop=e,document.body.scrollTop=e):t.scrollTop=e;
},u=function(n){
return void 0===n?e.getScrollTop():n.scrollTop;
};
return function(n){
var e=n.el,o=n.y,a=n.distance,s=n.speed,c=n.duration,d=n.easing,f=void 0===d?"easeOutSine":d,l=n.begin,m=n.end,p=n.beforeScroll;
"function"==typeof l&&l();
var v=u(e),h=0;
if(void 0!==o)a=o-v;else{
if(void 0===a)return void console.error("need param `y` or `distance`.");
o=a+v;
}
void 0===s&&(s=void 0!==c?a/c:2e3);
var w=Math.max(.1,Math.min(Math.abs(v-o)/s,.8)),M=function g(){
h+=1/60;
var n=h/w,u=i[f](n);
1>n?(t(g),r(p,v+(o-v)*u,e)):(r(p,o,e),"function"==typeof m&&m());
};
M();
};
});define("appmsg/related_article_feedback.js",["biz_wap/utils/ajax.js","biz_common/dom/class.js","biz_common/dom/event.js","biz_common/utils/url/parse.js","common/utils.js"],function(e){
"use strict";
function t(e,t){
for(;!e.parentNode.className.match(t);)e=e.parentNode;
return e.parentNode||"";
}
function i(e){
this.container=e.container,this.biz=e.biz,this.mid=e.mid,this.idx=e.idx,this.vid=e.vid,
this.isVideo=e.isVideo,this.dislikeCb=e.dislikeCb,s["top"===e.position?"addClass":"removeClass"](this.container.querySelector(".js_dialog_wrp"),"feedback_dialog_pos_top"),
this.bindEvent();
}
function a(e){
var a=e.container;
n.on(a,"touchstart",".js_feedback_btn",function(e){
e.stopPropagation();
},!0),n.on(a,"touchend",".js_feedback_btn",function(e){
e.stopPropagation();
},!0),n.on(a,"click",".js_feedback_btn",function(a){
a.stopPropagation();
var o=a.delegatedTarget,s=t(o,"js_related_item"),n=268;
l=new i({
container:s,
biz:e.biz,
mid:e.mid,
idx:e.idx,
isVideo:e.isVideo,
vid:e.vid,
position:r.getInnerHeight()-s.getBoundingClientRect().bottom<n?"top":"bottom",
dislikeCb:e.dislikeCb
}),l.show();
},!0);
}
var o=e("biz_wap/utils/ajax.js"),s=e("biz_common/dom/class.js"),n=e("biz_common/dom/event.js"),d=e("biz_common/utils/url/parse.js"),r=e("common/utils.js"),l=null;
return i.prototype.bindEvent=function(){
var e=this,i=this.container,a=this.biz,r=this.mid,l=this.idx,c=i.getAttribute("data-url"),u=new Set,_=new Set,m=i.querySelector(".js_submit");
this.tabClickEventHandler=function(e){
e.stopPropagation(),e.preventDefault();
var t=e.delegatedTarget,i=t.getAttribute("data-value");
s.hasClass(t,"js_reason")&&(i*=1),s.hasClass(t,"feedback_tag_selected")?(s.removeClass(t,"feedback_tag_selected"),
s.hasClass(t,"js_reason")?u.delete(i):_.delete(i)):(s.addClass(t,"feedback_tag_selected"),
s.hasClass(t,"js_reason")?u.add(i):_.add(i)),0===u.size&&0===_.size?s.addClass(m,"weui-btn_disabled"):s.removeClass(m,"weui-btn_disabled");
},this.submitDataHandler=function(n){
n.stopPropagation(),n.preventDefault();
var m=n.target;
if(!s.hasClass(m,"weui-btn_disabled")){
var h={
tacitly:Array.from(u),
keyword:Array.from(_)
},b={
biz_from:a,
mid_from:r,
idx_from:l,
recommended_biz:d.getQuery("__biz",c),
mid:d.getQuery("mid",c),
idx:d.getQuery("idx",c),
reason:JSON.stringify(h)
},p="/mp/relatedarticle?action=dislike";
e.isVideo&&(b.vid_from=e.vid,b.vid=i.getAttribute("data-vid"),p="/mp/video_similar?action=dislike"),
o({
type:"POST",
url:p,
dataType:"json",
data:b,
success:function(i){
if(console.log(i),i&&i.base_resp&&0===i.base_resp.ret){
e.hide(m);
var a=t(m,"js_related_item");
e.dislikeCb(a);
}else window.weui.alert("系统错误，请稍后重试");
}
});
}
},this.maskHandler=function(t){
t.stopPropagation(),t.preventDefault(),e.hide(t.target);
},this.maskTouchMoveHandler=function(e){
e.stopPropagation(),e.preventDefault();
},this.stopPropagationHandler=function(e){
e.stopPropagation();
},n.on(i,"click",".js_tag_item",this.tabClickEventHandler,!0),n.on(m,"click",this.submitDataHandler,!0),
n.on(i,"click",".js_mask",this.maskHandler,!0),n.on(i,"touchmove",".js_mask",this.maskTouchMoveHandler,!0),
n.on(i,"touchmove",".js_dialog_wrp",this.maskTouchMoveHandler,!0),n.on(i,"click",".js_dialog_wrp",this.maskTouchMoveHandler,!1),
n.on(i,"touchstart",".js_feedback_dialog",this.stopPropagationHandler,!0),n.on(i,"touchend",".js_feedback_dialog",this.stopPropagationHandler,!0);
},i.prototype.show=function(){
this.container.querySelector(".js_feedback_dialog").style.display="",s.addClass(this.container.querySelector(".js_feedback_dialog"),"feedback_dialog_show");
},i.prototype.hide=function(){
var e=this.container,t=e.querySelector(".js_submit");
n.off(e,"click",this.tabClickEventHandler,!0),n.off(t,"click",this.submitDataHandler,!0),
n.off(e,"click",this.maskHandler,!0),n.off(e,"touchmove",this.maskTouchMoveHandler,!0),
n.off(e,"click",this.maskTouchMoveHandler,!1),s.removeClass(this.container.querySelector(".js_feedback_dialog"),"feedback_dialog_show");
},{
init:a
};
});define("appmsg/related_article_item.html.js",[],function(){
return'<# list.forEach(function(item, idx) { #>\n  <a href="javascript:void(0);" class="weui-media-box weui-media-box_appmsg js_related_item"\n    data-index="<#=begin+idx#>"\n    data-url="<#=item.url#>"\n    data-time="<#=item.send_time#>"\n    data-recalltype="<#=item.recall_type#>"\n    data-isreaded="<#=item.is_readed#>"\n    data-bizuin="<#=item.bizuin#>"\n    data-mid="<#=item.mid#>"\n    data-idx="<#=item.idx#>"\n    data-item_show_type="<#=item.item_show_type#>"\n    data-exptype="<#=item.exptype#>"\n    data-ext_info="<#=item.ext_info#>"\n  >\n    <div class="weui-media-box__bd">\n      <!---\n      原生省略号无法实现多行省略号后接其它信息的效果\n      模拟省略号组件：style/widget/ellipsis.less\n      为了实现标题在省略号后显示标签，要做份假数据用来获取相同位置\n      另增加两种状态：省略号后不带标签、三个字标签\n      -->\n      <div class="ellipsis_relate_title weui_ellipsis_mod_wrp\n        <# if (item.is_pay_subscribe) { #>\n          <# if (item.is_paid) { #>\n          relate_article_pay\n          <# } else { #>\n          <# } #>\n        <# } else { #>\n          relate_article_default\n        <# } #>\n      ">\n        <div class="weui_ellipsis_mod">\n          <div class="weui_ellipsis_mod_inner">\n            <#=item.title#>\n            <# if (item.is_pay_subscribe) { #>\n              <# if (item.is_paid) { #>\n                <span class="pay__tag">已付费</span>\n              <# } else { #>\n                <span class="unpay__tag">付费</span>\n              <# } #>\n            <# } #>\n          </div>\n        </div>\n        <div class="weui_ellipsis_fake_mod">\n          <div class="weui_ellipsis_fake_inner">\n            <#=item.title#>\n            <# if (item.is_pay_subscribe) { #>\n              <# if (item.is_paid) { #>\n                <span class="pay__tag">已付费</span>\n              <# } else { #>\n                <span class="unpay__tag">付费</span>\n              <# } #>\n            <# } #>\n          </div>\n          <div class="weui_ellipsis_fake_placeholder"></div>\n          <div class="weui_ellipsis_fake_extra">...\n            <# if (item.is_pay_subscribe) { #>\n              <# if (item.is_paid) { #>\n                <span class="pay__tag">已付费</span>\n              <# } else { #>\n                <span class="unpay__tag">付费</span>\n              <# } #>\n            <# } #>\n          </div>\n        </div>\n      </div>\n      <div class="weui-media-box__info">\n        <div class="weui-media-box__info__inner">\n          <div class="weui-media-box__info__meta">\n            <# if (item.old_like_num >= 10) { #>\n              赞 <#=item.like_num_wording#>            <# } else if (item.is_pay_subscribe && item.pay_cnt) { #>\n              付费 <#=item.pay_cnt_wording#>            <# } else if (item.read_num) { #>\n              阅读 <#=item.read_num_wording#>            <# } #>\n          </div>\n          <div class="js_profile relate_profile relate_article_panel_active" data-username="<#=item.username#>">\n            <div class="weui-media-box__info__meta">\n              <span class="relate_profile_nickname">\n                <#=item.nickname#>\n              </span>\n            </div>\n          </div>\n        </div>\n        <div class="relate_article_opr">\n          <button type="button" class="reset_btn dislike_btn js_feedback_btn">不喜欢</button>\n        </div>\n        <!-- 去掉display:none;改用样式默认隐藏，加classnamme:feedback_dialog_show显示 -->\n        <div class="feedback_dialog_wrp js_feedback_dialog">\n          <div class="weui-mask js_mask"></div>\n          <!-- 底部时弹窗向上，加.feedback_dialog_pos_top -->\n          <div class="feedback_dialog js_dialog_wrp">\n            <div class="feedback_dialog_hd weui-flex">\n              <div class="weui-flex__item feedback_dialog_title">不看的原因</div>\n              <button type="button" class="weui-btn weui-btn_primary weui-btn_mini weui-btn_disabled js_submit">确定</button>\n            </div>\n            <div class="feedback_dialog_bd">\n              <ul class="feedback_tag_list">\n                <!-- 选中时tag加.feedback_tag_selected -->\n                <# reason.forEach(function(r) { #>\n                  <li class="feedback_tag_item js_reason js_tag_item" data-value="<#=r.value#>"><#=r.name#></li>\n                <# }); #>\n                <# item.keyword.forEach(function(k,i) { #>\n                  <# if (i<2) { #>\n                    <li class="feedback_tag_item js_keyword js_tag_item" data-value="<#=k#>">对<#=k#>不感兴趣</li>\n                  <# } #>\n                <# }); #>\n              </ul>\n            </div>\n          </div>\n        </div>\n      </div>\n    </div>\n    <div class="weui-media-box__ft" style="background-image:url(<#=item.cover#>)"></div>\n  </a>\n<# }); #>';
});define("appmsg/related_article_tpl.html.js",[],function(){
return'<div class="relate_mod_transition function_mod js_related_area" style="opacity: 1; overflow: hidden; height: 0; margin: 0;">\n  <div class="function_mod_index js_related_main">\n      <div class="function_hd js_related_title">\n        <# if (type === \'share\') { #> <!-- 分享 -->\n          分享此内容的人还喜欢        <# } else if (type === \'favorite\') { #> <!-- 收藏 -->\n          收藏此内容的人还喜欢        <# } else if (type === \'praise\' || type === \'like\') { #> <!-- 点赞/在看 -->\n          喜欢此内容的人还喜欢        <# } else { #> <!-- 其它 -->\n          喜欢此内容的人还喜欢        <# } #>\n      </div>\n      <div class="function_bd">\n          <div class="relate_article_list relate_article_placeholder js_related_placeholder">\n              <div class="weui-media-box weui-media-box_appmsg"><div class="weui-media-box_placeholder"></div></div>\n              <div class="weui-media-box weui-media-box_appmsg"><div class="weui-media-box_placeholder"></div></div>\n              <div class="weui-media-box weui-media-box_appmsg"><div class="weui-media-box_placeholder"></div></div>\n          </div>\n          <div class="relate_article_index_list relate_article_list js_related_list" style="height: auto;"></div>\n      </div>\n  </div>\n</div>\n';
});define("complain/utils/utils.js",["biz_common/tmpl.js"],function(r,t,n){
"use strict";
function e(r,t){
var n=t||window.location.search,e=new RegExp("(^|&)"+r+"=([^&]*)(&|$)"),i=n.substr(n.indexOf("?")+1).match(e);
return null!=i?i[2]:"";
}
function i(r,t,n){
var e="string"==typeof t?t.split("."):t;
if(1===e.length)return void(r[t]=n);
var o=e.shift();
i(r[o],e,n);
}
function o(){
var r;
return Array.from?(r=Array).from.apply(r,arguments):[].slice.call(arguments[0]);
}
function u(r,t,n){
var e=r;
"string"==typeof r&&(e=document.querySelector(r)),e.innerHTML=a.tmpl(t,n);
}
var a=r("biz_common/tmpl.js"),s=function(){
return(65536*(1+Math.random())|0).toString(16).substring(1);
},c=function(r){
return Array.prototype.slice.call(r,0);
};
n.exports={
uuid:s,
toArray:c,
getQuery:e,
set:i,
arrayfrom:o,
renderTpl:u
};
});