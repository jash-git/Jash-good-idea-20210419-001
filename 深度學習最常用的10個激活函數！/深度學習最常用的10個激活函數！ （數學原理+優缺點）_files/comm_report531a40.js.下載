define("biz_wap/utils/ajax_load_js.js",["biz_wap/utils/ajax.js","biz_wap/utils/localstorage.js"],function(e){
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
if("link"===n&&E.is_teenager)return weui.alert("青少年模式下不可赞赏"),void T.setSum(232209,0,1);
if("0"==E.user_can_reward)return void r("你已成为该公众号的黑名单用户，暂时无法赞赏。");
if(t.preventDefault(),E.isWindowsWechat){
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
},r=function(n,e){
void 0===e?(document.documentElement.scrollTop=n,document.body.scrollTop=n):e.scrollTop=n;
},u=function(n){
return void 0===n?e.getScrollTop():n.scrollTop;
};
return function(n){
var e=n.el,o=n.y,a=n.distance,s=n.speed,c=n.duration,d=n.easing,f=void 0===d?"easeOutSine":d,l=n.begin,m=n.end;
"function"==typeof l&&l();
var v=u(e),p=0;
if(void 0!==o)a=o-v;else{
if(void 0===a)return void console.error("need param `y` or `distance`.");
o=a+v;
}
void 0===s&&(s=void 0!==c?a/c:2e3);
var h=Math.max(.1,Math.min(Math.abs(v-o)/s,.8)),w=function M(){
p+=1/60;
var n=p/h,u=i[f](n);
1>n?(t(M),r(v+(o-v)*u,e)):(r(o,e),"function"==typeof m&&m());
};
w();
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
});define("appmsg/i18n.js",[],function(e,n){
"use strict";
n.dealLikeReadShow_en=function(e){
if("undefined"==typeof LANG||!LANG)return 0===parseInt(e)?"":e;
if("en"==LANG){
var n="";
if(parseInt(e)>1e5)n="100k+";else if(parseInt(e)>1e4&&parseInt(e)<=1e5){
var r=""+parseInt(e)/1e3,t=r.indexOf(".");
n=-1===t?r+"k":r.substr(0,t)+"."+r.charAt(t+1)+"k";
}else n=0===parseInt(e)?"":e;
return n;
}
return"";
};
});!function(e){
var c="object"==typeof window&&window||"object"==typeof self&&self;
"function"==typeof define?define("biz_common/utils/emoji_data.js",[],function(c,o){
"use strict";
return e(o);
}):c&&"undefined"==typeof c.__emojiData&&(c.__emojiData=e({}));
}(function(){
return[{
id:0,
cn:"[微笑]",
hk:"[微笑]",
us:"[Smile]",
code:"/::)",
web_code:"/微笑",
style:"icon_smiley_0"
},{
id:1,
cn:"[撇嘴]",
hk:"[撇嘴]",
us:"[Grimace]",
code:"/::~",
web_code:"/撇嘴",
style:"icon_smiley_1"
},{
id:2,
cn:"[色]",
hk:"[色]",
us:"[Drool]",
code:"/::B",
web_code:"/色",
style:"icon_smiley_2"
},{
id:3,
cn:"[发呆]",
hk:"[發呆]",
us:"[Scowl]",
code:"/::|",
web_code:"/发呆",
style:"icon_smiley_3"
},{
id:4,
cn:"[得意]",
hk:"[得意]",
us:"[CoolGuy]",
code:"/:8-)",
web_code:"/得意",
style:"icon_smiley_4"
},{
id:5,
cn:"[流泪]",
hk:"[流淚]",
us:"[Sob]",
code:"/::<",
web_code:"/流泪",
style:"icon_smiley_5"
},{
id:6,
cn:"[害羞]",
hk:"[害羞]",
us:"[Shy]",
code:"/::$",
web_code:"/害羞",
style:"icon_smiley_6"
},{
id:7,
cn:"[闭嘴]",
hk:"[閉嘴]",
us:"[Silent]",
code:"/::X",
web_code:"/闭嘴",
style:"icon_smiley_7"
},{
id:8,
cn:"[睡]",
hk:"[睡]",
us:"[Sleep]",
code:"/::Z",
web_code:"/睡",
style:"icon_smiley_8"
},{
id:9,
cn:"[大哭]",
hk:"[大哭]",
us:"[Cry]",
code:"/::'(",
web_code:"/大哭",
style:"icon_smiley_9"
},{
id:10,
cn:"[尴尬]",
hk:"[尷尬]",
us:"[Awkward]",
code:"/::-|",
web_code:"/尴尬",
style:"icon_smiley_10"
},{
id:11,
cn:"[发怒]",
hk:"[發怒]",
us:"[Angry]",
code:"/::@",
web_code:"/发怒",
style:"icon_smiley_11"
},{
id:12,
cn:"[调皮]",
hk:"[調皮]",
us:"[Tongue]",
code:"/::P",
web_code:"/调皮",
style:"icon_smiley_12"
},{
id:13,
cn:"[呲牙]",
hk:"[呲牙]",
us:"[Grin]",
code:"/::D",
web_code:"/呲牙",
style:"icon_smiley_13"
},{
id:14,
cn:"[惊讶]",
hk:"[驚訝]",
us:"[Surprise]",
code:"/::O",
web_code:"/惊讶",
style:"icon_smiley_14"
},{
id:15,
cn:"[难过]",
hk:"[難過]",
us:"[Frown]",
code:"/::(",
web_code:"/难过",
style:"icon_smiley_15"
},{
id:16,
cn:"[酷]",
hk:"[酷]",
us:"[Ruthless]",
code:"/::+",
web_code:"/酷",
style:"icon_smiley_16"
},{
id:17,
cn:"[冷汗]",
hk:"[冷汗]",
us:"[Blush]",
code:"/:--b",
web_code:"/冷汗",
style:"icon_smiley_17"
},{
id:18,
cn:"[抓狂]",
hk:"[抓狂]",
us:"[Scream]",
code:"/::Q",
web_code:"/抓狂",
style:"icon_smiley_18"
},{
id:19,
cn:"[吐]",
hk:"[吐]",
us:"[Puke]",
code:"/::T",
web_code:"/吐",
style:"icon_smiley_19"
},{
id:20,
cn:"[偷笑]",
hk:"[偷笑]",
us:"[Chuckle]",
code:"/:,@P",
web_code:"/偷笑",
style:"icon_smiley_20"
},{
id:21,
cn:"[愉快]",
hk:"[愉快]",
us:"[Joyful]",
code:"/:,@-D",
web_code:"/可爱",
style:"icon_smiley_21"
},{
id:22,
cn:"[白眼]",
hk:"[白眼]",
us:"[Slight]",
code:"/::d",
web_code:"/白眼",
style:"icon_smiley_22"
},{
id:23,
cn:"[傲慢]",
hk:"[傲慢]",
us:"[Smug]",
code:"/:,@o",
web_code:"/傲慢",
style:"icon_smiley_23"
},{
id:24,
cn:"[饥饿]",
hk:"[饑餓]",
us:"[Hungry]",
code:"/::g",
web_code:"/饥饿",
style:"icon_smiley_24"
},{
id:25,
cn:"[困]",
hk:"[累]",
us:"[Drowsy]",
code:"/:|-)",
web_code:"/困",
style:"icon_smiley_25"
},{
id:26,
cn:"[惊恐]",
hk:"[驚恐]",
us:"[Panic]",
code:"/::!",
web_code:"/惊恐",
style:"icon_smiley_26"
},{
id:27,
cn:"[流汗]",
hk:"[流汗]",
us:"[Sweat]",
code:"/::L",
web_code:"/流汗",
style:"icon_smiley_27"
},{
id:28,
cn:"[憨笑]",
hk:"[大笑]",
us:"[Laugh]",
code:"/::>",
web_code:"/憨笑",
style:"icon_smiley_28"
},{
id:29,
cn:"[悠闲]",
hk:"[悠閑]",
us:"[Commando]",
code:"/::,@",
web_code:"/大兵",
style:"icon_smiley_29"
},{
id:30,
cn:"[奋斗]",
hk:"[奮鬥]",
us:"[Determined]",
code:"/:,@f",
web_code:"/奋斗",
style:"icon_smiley_30"
},{
id:31,
cn:"[咒骂]",
hk:"[咒罵]",
us:"[Scold]",
code:"/::-S",
web_code:"/咒骂",
style:"icon_smiley_31"
},{
id:32,
cn:"[疑问]",
hk:"[疑問]",
us:"[Shocked]",
code:"/:?",
web_code:"/疑问",
style:"icon_smiley_32"
},{
id:33,
cn:"[嘘]",
hk:"[噓]",
us:"[Shhh]",
code:"/:,@x",
web_code:"/嘘",
style:"icon_smiley_33"
},{
id:34,
cn:"[晕]",
hk:"[暈]",
us:"[Dizzy]",
code:"/:,@@",
web_code:"/晕",
style:"icon_smiley_34"
},{
id:35,
cn:"[疯了]",
hk:"[瘋了]",
us:"[Tormented]",
code:"/::8",
web_code:"/折磨",
style:"icon_smiley_35"
},{
id:36,
cn:"[衰]",
hk:"[衰]",
us:"[Toasted]",
code:"/:,@!",
web_code:"/衰",
style:"icon_smiley_36"
},{
id:37,
cn:"[骷髅]",
hk:"[骷髏頭]",
us:"[Skull]",
code:"/:!!!",
web_code:"/骷髅",
style:"icon_smiley_37"
},{
id:38,
cn:"[敲打]",
hk:"[敲打]",
us:"[Hammer]",
code:"/:xx",
web_code:"/敲打",
style:"icon_smiley_38"
},{
id:39,
cn:"[再见]",
hk:"[再見]",
us:"[Wave]",
code:"/:bye",
web_code:"/再见",
style:"icon_smiley_39"
},{
id:40,
cn:"[擦汗]",
hk:"[擦汗]",
us:"[Speechless]",
code:"/:wipe",
web_code:"/擦汗",
style:"icon_smiley_40"
},{
id:41,
cn:"[抠鼻]",
hk:"[摳鼻]",
us:"[NosePick]",
code:"/:dig",
web_code:"/抠鼻",
style:"icon_smiley_41"
},{
id:42,
cn:"[鼓掌]",
hk:"[鼓掌]",
us:"[Clap]",
code:"/:handclap",
web_code:"/鼓掌",
style:"icon_smiley_42"
},{
id:43,
cn:"[糗大了]",
hk:"[羞辱]",
us:"[Shame]",
code:"/:&-(",
web_code:"/糗大了",
style:"icon_smiley_43"
},{
id:44,
cn:"[坏笑]",
hk:"[壞笑]",
us:"[Trick]",
code:"/:B-)",
web_code:"/坏笑",
style:"icon_smiley_44"
},{
id:45,
cn:"[左哼哼]",
hk:"[左哼哼]",
us:"[Bah！L]",
code:"/:<@",
web_code:"/左哼哼",
style:"icon_smiley_45"
},{
id:46,
cn:"[右哼哼]",
hk:"[右哼哼]",
us:"[Bah！R]",
code:"/:@>",
web_code:"/右哼哼",
style:"icon_smiley_46"
},{
id:47,
cn:"[哈欠]",
hk:"[哈欠]",
us:"[Yawn]",
code:"/::-O",
web_code:"/哈欠",
style:"icon_smiley_47"
},{
id:48,
cn:"[鄙视]",
hk:"[鄙視]",
us:"[Pooh-pooh]",
code:"/:>-|",
web_code:"/鄙视",
style:"icon_smiley_48"
},{
id:49,
cn:"[委屈]",
hk:"[委屈]",
us:"[Shrunken]",
code:"/:P-(",
web_code:"/委屈",
style:"icon_smiley_49"
},{
id:50,
cn:"[快哭了]",
hk:"[快哭了]",
us:"[TearingUp]",
code:"/::'|",
web_code:"/快哭了",
style:"icon_smiley_50"
},{
id:51,
cn:"[阴险]",
hk:"[陰險]",
us:"[Sly]",
code:"/:X-)",
web_code:"/阴险",
style:"icon_smiley_51"
},{
id:52,
cn:"[亲亲]",
hk:"[親親]",
us:"[Kiss]",
code:"/::*",
web_code:"/亲亲",
style:"icon_smiley_52"
},{
id:53,
cn:"[吓]",
hk:"[嚇]",
us:"[Wrath]",
code:"/:@x",
web_code:"/吓",
style:"icon_smiley_53"
},{
id:54,
cn:"[可怜]",
hk:"[可憐]",
us:"[Whimper]",
code:"/:8*",
web_code:"/可怜",
style:"icon_smiley_54"
},{
id:55,
cn:"[菜刀]",
hk:"[菜刀]",
us:"[Cleaver]",
code:"/:pd",
web_code:"/菜刀",
style:"icon_smiley_55"
},{
id:56,
cn:"[西瓜]",
hk:"[西瓜]",
us:"[Watermelon]",
code:"/:<W>",
web_code:"/西瓜",
style:"icon_smiley_56"
},{
id:57,
cn:"[啤酒]",
hk:"[啤酒]",
us:"[Beer]",
code:"/:beer",
web_code:"/啤酒",
style:"icon_smiley_57"
},{
id:58,
cn:"[篮球]",
hk:"[籃球]",
us:"[Basketball]",
code:"/:basketb",
web_code:"/篮球",
style:"icon_smiley_58"
},{
id:59,
cn:"[乒乓]",
hk:"[乒乓]",
us:"[PingPong]",
code:"/:oo",
web_code:"/乒乓",
style:"icon_smiley_59"
},{
id:60,
cn:"[咖啡]",
hk:"[咖啡]",
us:"[Coffee]",
code:"/:coffee",
web_code:"/咖啡",
style:"icon_smiley_60"
},{
id:61,
cn:"[饭]",
hk:"[飯]",
us:"[Rice]",
code:"/:eat",
web_code:"/饭",
style:"icon_smiley_61"
},{
id:62,
cn:"[猪头]",
hk:"[豬頭]",
us:"[Pig]",
code:"/:pig",
web_code:"/猪头",
style:"icon_smiley_62"
},{
id:63,
cn:"[玫瑰]",
hk:"[玫瑰]",
us:"[Rose]",
code:"/:rose",
web_code:"/玫瑰",
style:"icon_smiley_63"
},{
id:64,
cn:"[凋谢]",
hk:"[枯萎]",
us:"[Wilt]",
code:"/:fade",
web_code:"/凋谢",
style:"icon_smiley_64"
},{
id:65,
cn:"[嘴唇]",
hk:"[嘴唇]",
us:"[Lips]",
code:"/:showlove",
web_code:"/示爱",
style:"icon_smiley_65"
},{
id:66,
cn:"[爱心]",
hk:"[愛心]",
us:"[Heart]",
code:"/:heart",
web_code:"/爱心",
style:"icon_smiley_66"
},{
id:67,
cn:"[心碎]",
hk:"[心碎]",
us:"[BrokenHeart]",
code:"/:break",
web_code:"/心碎",
style:"icon_smiley_67"
},{
id:68,
cn:"[蛋糕]",
hk:"[蛋糕]",
us:"[Cake]",
code:"/:cake",
web_code:"/蛋糕",
style:"icon_smiley_68"
},{
id:69,
cn:"[闪电]",
hk:"[閃電]",
us:"[Lightning]",
code:"/:li",
web_code:"/闪电",
style:"icon_smiley_69"
},{
id:70,
cn:"[炸弹]",
hk:"[炸彈]",
us:"[Bomb]",
code:"/:bome",
web_code:"/炸弹",
style:"icon_smiley_70"
},{
id:71,
cn:"[刀]",
hk:"[刀]",
us:"[Dagger]",
code:"/:kn",
web_code:"/刀",
style:"icon_smiley_71"
},{
id:72,
cn:"[足球]",
hk:"[足球]",
us:"[Soccer]",
code:"/:footb",
web_code:"/足球",
style:"icon_smiley_72"
},{
id:73,
cn:"[瓢虫]",
hk:"[甲蟲]",
us:"[Ladybug]",
code:"/:ladybug",
web_code:"/瓢虫",
style:"icon_smiley_73"
},{
id:74,
cn:"[便便]",
hk:"[便便]",
us:"[Poop]",
code:"/:shit",
web_code:"/便便",
style:"icon_smiley_74"
},{
id:75,
cn:"[月亮]",
hk:"[月亮]",
us:"[Moon]",
code:"/:moon",
web_code:"/月亮",
style:"icon_smiley_75"
},{
id:76,
cn:"[太阳]",
hk:"[太陽]",
us:"[Sun]",
code:"/:sun",
web_code:"/太阳",
style:"icon_smiley_76"
},{
id:77,
cn:"[礼物]",
hk:"[禮物]",
us:"[Gift]",
code:"/:gift",
web_code:"/礼物",
style:"icon_smiley_77"
},{
id:78,
cn:"[拥抱]",
hk:"[擁抱]",
us:"[Hug]",
code:"/:hug",
web_code:"/拥抱",
style:"icon_smiley_78"
},{
id:79,
cn:"[强]",
hk:"[強]",
us:"[ThumbsUp]",
code:"/:strong",
web_code:"/强",
style:"icon_smiley_79"
},{
id:80,
cn:"[弱]",
hk:"[弱]",
us:"[ThumbsDown]",
code:"/:weak",
web_code:"/弱",
style:"icon_smiley_80"
},{
id:81,
cn:"[握手]",
hk:"[握手]",
us:"[Shake]",
code:"/:share",
web_code:"/握手",
style:"icon_smiley_81"
},{
id:82,
cn:"[胜利]",
hk:"[勝利]",
us:"[Peace]",
code:"/:v",
web_code:"/胜利",
style:"icon_smiley_82"
},{
id:83,
cn:"[抱拳]",
hk:"[抱拳]",
us:"[Fight]",
code:"/:@)",
web_code:"/抱拳",
style:"icon_smiley_83"
},{
id:84,
cn:"[勾引]",
hk:"[勾引]",
us:"[Beckon]",
code:"/:jj",
web_code:"/勾引",
style:"icon_smiley_84"
},{
id:85,
cn:"[拳头]",
hk:"[拳頭]",
us:"[Fist]",
code:"/:@@",
web_code:"/拳头",
style:"icon_smiley_85"
},{
id:86,
cn:"[差劲]",
hk:"[差勁]",
us:"[Pinky]",
code:"/:bad",
web_code:"/差劲",
style:"icon_smiley_86"
},{
id:87,
cn:"[爱你]",
hk:"[愛你]",
us:"[RockOn]",
code:"/:lvu",
web_code:"/爱你",
style:"icon_smiley_87"
},{
id:88,
cn:"[NO]",
hk:"[NO]",
us:"[Nuh-uh]",
code:"/:no",
web_code:"/NO",
style:"icon_smiley_88"
},{
id:89,
cn:"[OK]",
hk:"[OK]",
us:"[OK]",
code:"/:ok",
web_code:"/OK",
style:"icon_smiley_89"
},{
id:90,
cn:"[爱情]",
hk:"[愛情]",
us:"[InLove]",
code:"/:love",
web_code:"/爱情",
style:"icon_smiley_90"
},{
id:91,
cn:"[飞吻]",
hk:"[飛吻]",
us:"[Blowkiss]",
code:"/:<L>",
web_code:"/飞吻",
style:"icon_smiley_91"
},{
id:92,
cn:"[跳跳]",
hk:"[跳跳]",
us:"[Waddle]",
code:"/:jump",
web_code:"/跳跳",
style:"icon_smiley_92"
},{
id:93,
cn:"[发抖]",
hk:"[發抖]",
us:"[Tremble]",
code:"/:shake",
web_code:"/发抖",
style:"icon_smiley_93"
},{
id:94,
cn:"[怄火]",
hk:"[噴火]",
us:"[Aaagh!]",
code:"/:<O>",
web_code:"/怄火",
style:"icon_smiley_94"
},{
id:95,
cn:"[转圈]",
hk:"[轉圈]",
us:"[Twirl]",
code:"/:circle",
web_code:"/转圈",
style:"icon_smiley_95"
},{
id:96,
cn:"[磕头]",
hk:"[磕頭]",
us:"[Kotow]",
code:"/:kotow",
web_code:"/磕头",
style:"icon_smiley_96"
},{
id:97,
cn:"[回头]",
hk:"[回頭]",
us:"[Dramatic]",
code:"/:turn",
web_code:"/回头",
style:"icon_smiley_97"
},{
id:98,
cn:"[跳绳]",
hk:"[跳繩]",
us:"[JumpRope]",
code:"/:skip",
web_code:"/跳绳",
style:"icon_smiley_98"
},{
id:99,
cn:"[投降]",
hk:"[投降]",
us:"[Surrender]",
code:"/:oY",
web_code:"/挥手",
style:"icon_smiley_99"
},{
id:100,
cn:"[激动]",
hk:"[激動]",
us:"[Hooray]",
code:"/:#-0",
web_code:"/激动",
style:"icon_smiley_100"
},{
id:101,
cn:"[乱舞]",
hk:"[亂舞]",
us:"[Meditate]",
code:"/:hiphot",
web_code:"/街舞",
style:"icon_smiley_101"
},{
id:102,
cn:"[献吻]",
hk:"[獻吻]",
us:"[Smooch]",
code:"/:kiss",
web_code:"/献吻",
style:"icon_smiley_102"
},{
id:103,
cn:"[左太极]",
hk:"[左太極]",
us:"[TaiChi L]",
code:"/:<&",
web_code:"/左太极",
style:"icon_smiley_103"
},{
id:104,
cn:"[右太极]",
hk:"[右太極]",
us:"[TaiChi R]",
code:"/:&>",
web_code:"/右太极",
style:"icon_smiley_104"
},{
id:204,
cn:"[嘿哈]",
hk:"[吼嘿]",
us:"[Hey]",
code:"",
web_code:"",
style:"icon_emoji_wx_4"
},{
id:205,
cn:"[捂脸]",
hk:"[掩面]",
us:"[Facepalm]",
code:"",
web_code:"",
style:"icon_emoji_wx_5"
},{
id:202,
cn:"[奸笑]",
hk:"[奸笑]",
us:"[Smirk]",
code:"",
web_code:"",
style:"icon_emoji_wx_2"
},{
id:206,
cn:"[机智]",
hk:"[機智]",
us:"[Smart]",
code:"",
web_code:"",
style:"icon_emoji_wx_6"
},{
id:212,
cn:"[皱眉]",
hk:"[皺眉]",
us:"[Moue]",
code:"",
web_code:"",
style:"icon_emoji_wx_12"
},{
id:211,
cn:"[耶]",
hk:"[歐耶]",
us:"[Yeah!]",
code:"",
web_code:"",
style:"icon_emoji_wx_11"
},{
id:207,
cn:"[茶]",
hk:"[茶]",
us:"[Tea]",
code:"",
web_code:"",
style:"icon_emoji_wx_7"
},{
id:209,
cn:"[红包]",
hk:"[Packet]",
us:"[Packet]",
code:"",
web_code:"",
style:"icon_emoji_wx_9"
},{
id:210,
cn:"[蜡烛]",
hk:"[蠟燭]",
us:"[Candle]",
code:"",
web_code:"",
style:"icon_emoji_wx_10"
},{
id:215,
cn:"[福]",
hk:"[福]",
us:"[Blessing]",
code:"",
web_code:"",
style:"icon_emoji_wx_15"
},{
id:214,
cn:"[鸡]",
hk:"[小雞]",
us:"[Chick]",
code:"",
web_code:"",
style:"icon_emoji_wx_14"
},{
id:300,
cn:"[笑脸]",
emoji:"😄",
hk:"",
us:"",
code:"\\ue415",
web_code:"",
style:"icon_emoji_ios_0"
},{
id:301,
cn:"[生病]",
emoji:"😷",
hk:"",
us:"",
code:"\\ue40c",
web_code:"",
style:"icon_emoji_ios_1"
},{
id:302,
cn:"[破涕为笑]",
emoji:"😂",
hk:"",
us:"",
code:"\\ue412",
web_code:"",
style:"icon_emoji_ios_2"
},{
id:303,
cn:"[吐舌]",
emoji:"😝",
hk:"",
us:"",
code:"\\ue409",
web_code:"",
style:"icon_emoji_ios_3"
},{
id:304,
cn:"[脸红]",
emoji:"😳",
hk:"",
us:"",
code:"\\ue40d",
web_code:"",
style:"icon_emoji_ios_4"
},{
id:305,
cn:"[恐惧]",
emoji:"😱",
hk:"",
us:"",
code:"\\ue107",
web_code:"",
style:"icon_emoji_ios_5"
},{
id:306,
cn:"[失望]",
emoji:"😔",
hk:"",
us:"",
code:"\\ue403",
web_code:"",
style:"icon_emoji_ios_6"
},{
id:307,
cn:"[无语]",
emoji:"😒",
hk:"",
us:"",
code:"\\ue40e",
web_code:"",
style:"icon_emoji_ios_7"
},{
id:308,
cn:"[鬼魂]",
emoji:"👻",
hk:"",
us:"",
code:"\\ue11b",
web_code:"",
style:"icon_emoji_ios_8"
},{
id:309,
cn:"[合十]",
emoji:"🙏",
hk:"",
us:"",
code:"\\ue41d",
web_code:"",
style:"icon_emoji_ios_9"
},{
id:310,
cn:"[强壮]",
emoji:"💪",
hk:"",
us:"",
code:"\\ue14c",
web_code:"",
style:"icon_emoji_ios_10"
},{
id:311,
cn:"[庆祝]",
emoji:"🎉",
hk:"",
us:"",
code:"\\ue312",
web_code:"",
style:"icon_emoji_ios_11"
},{
id:312,
cn:"[礼物]",
emoji:"🎁",
hk:"",
us:"",
code:"\\ue112",
web_code:"",
style:"icon_emoji_ios_12"
},{
id:313,
cn:"[吃瓜]",
hk:"[吃西瓜]",
us:"[Onlooker]",
code:"",
web_code:"",
style:"icon_emoji_wx_Watermelon"
},{
id:314,
cn:"[加油]",
hk:"[加油]",
us:"[GoForIt]",
code:"",
web_code:"",
style:"icon_emoji_wx_Addoil"
},{
id:315,
cn:"[汗]",
hk:"[汗]",
us:"[Sweats]",
code:"",
web_code:"",
style:"icon_emoji_wx_Sweat"
},{
id:316,
cn:"[天啊]",
hk:"[天啊]",
us:"[OMG]",
code:"",
web_code:"",
style:"icon_emoji_wx_Shocked"
},{
id:317,
cn:"[Emm]",
hk:"[一言難盡]",
us:"[Emm]",
code:"",
web_code:"",
style:"icon_emoji_wx_Cold"
},{
id:318,
cn:"[社会社会]",
hk:"[失敬失敬]",
us:"[Respect]",
code:"",
web_code:"",
style:"icon_emoji_wx_Social"
},{
id:319,
cn:"[旺柴]",
hk:"[旺柴]",
us:"[Doge]",
code:"",
web_code:"",
style:"icon_emoji_wx_Yellowdog"
},{
id:320,
cn:"[好的]",
hk:"[好的]",
us:"[NoProb]",
code:"",
web_code:"",
style:"icon_emoji_wx_NoProb"
},{
id:321,
cn:"[打脸]",
hk:"[打臉]",
us:"[MyBad]",
code:"",
web_code:"",
style:"icon_emoji_wx_Slap"
},{
id:322,
cn:"[加油加油]",
hk:"[加油！]",
us:"[KeepFighting]",
code:"",
web_code:"",
style:"icon_emoji_wx_KeepFighting"
},{
id:323,
cn:"[哇]",
hk:"[哇]",
us:"[Wow]",
code:"",
web_code:"",
style:"icon_emoji_wx_Wow"
},{
id:324,
cn:"[發]",
hk:"[發]",
us:"[Rich]",
code:"",
web_code:"",
style:"icon_emoji_wx_16"
},{
id:"17_1",
cn:"[囧]",
hk:"[囧]",
us:"[Blush]",
code:"",
web_code:"",
style:"icon_smiley_17"
},{
id:"39_1",
cn:"[再见]",
hk:"[再見]",
us:"[Bye]",
code:"",
web_code:"",
style:"icon_smiley_39"
},{
id:"83_1",
cn:"[抱拳]",
hk:"[抱拳]",
us:"[Salute]",
code:"",
web_code:"",
style:"icon_smiley_83"
},{
id:"212_1",
cn:"[皱眉]",
hk:"[皺眉]",
us:"[Concerned]",
code:"",
web_code:"",
style:"icon_emoji_wx_12"
},{
id:325,
cn:"[裂开]",
hk:"[崩潰]",
us:"[Broken]",
code:"",
web_code:"",
style:"icon_emoji_wx_Broken"
},{
id:326,
cn:"[苦涩]",
hk:"[難受]",
us:"[Hurt]",
code:"",
web_code:"",
style:"icon_emoji_wx_Hurt"
},{
id:327,
cn:"[叹气]",
hk:"[嘆息]",
us:"[Sigh]",
code:"",
web_code:"",
style:"icon_emoji_wx_Sigh"
},{
id:328,
cn:"[让我看看]",
hk:"[讓我看看]",
us:"[LetMeSee]",
code:"",
web_code:"",
style:"icon_emoji_wx_LetMeSee"
},{
id:329,
cn:"[666]",
hk:"[666]",
us:"[Awesome]",
code:"",
web_code:"",
style:"icon_emoji_wx_Awesome"
},{
id:330,
cn:"[翻白眼]",
hk:"[翻白眼]",
us:"[Boring]",
code:"",
web_code:"",
style:"icon_emoji_wx_Boring"
}];
});define("biz_wap/utils/openUrl.js",["biz_wap/jsapi/core.js","biz_wap/utils/mmversion.js"],function(e){
"use strict";
function r(e){
var r=document.createElement("a");
return r.href=e,{
source:e,
protocol:r.protocol.replace(":",""),
host:r.hostname,
port:r.port,
query:r.search,
params:function(){
for(var e,t={},i=r.search.replace(/^\?/,"").split("&"),a=i.length,o=0;a>o;o++)i[o]&&(e=i[o].split("="),
t[e[0]]=e[1]);
return t;
}(),
file:(r.pathname.match(/([^\/?#]+)$/i)||[,""])[1],
hash:r.hash.replace("#",""),
path:r.pathname.replace(/^([^\/])/,"/$1"),
relative:(r.href.match(/tps?:\/\/[^\/]+(.+)/)||[,""])[1],
segments:r.pathname.replace(/^\//,"").split("/")
};
}
function t(e,t){
var o;
t=t||1,0==e.indexOf("/")&&(o=r(location.href),e=o.protocol+"://"+o.host+e,console.log("openUrlWithExtraWebview with relative path:",e)),
e=e.replace(/(#[^#]*)+/,function(e,r){
return r;
}),-1!==navigator.userAgent.indexOf("MicroMessenger")&&(a.isIOS||a.isAndroid||a.isWp)?i.invoke("openUrlWithExtraWebview",{
url:e,
openType:t
},function(r){
-1==r.err_msg.indexOf("ok")&&(location.href=e);
}):location.href=e;
}
var i=e("biz_wap/jsapi/core.js"),a=e("biz_wap/utils/mmversion.js");
return{
openUrlWithExtraWebview:t
};
});function _defineProperty(e,t,n){
return t in e?Object.defineProperty(e,t,{
value:n,
enumerable:!0,
configurable:!0,
writable:!0
}):e[t]=n,e;
}
function _typeof(e){
return e&&"undefined"!=typeof Symbol&&e.constructor===Symbol?"symbol":typeof e;
}
var _extends=Object.assign||function(e){
for(var t=1;t<arguments.length;t++){
var n=arguments[t];
for(var i in n)Object.prototype.hasOwnProperty.call(n,i)&&(e[i]=n[i]);
}
return e;
};
define("video/video_tail_utils.js",["biz_wap/utils/ajax.js","biz_wap/jsapi/core.js","a/a_config.js","biz_common/utils/url/parse.js","a/a_utils.js","biz_wap/utils/mmversion.js","pages/utils.js","common/comm_report.js","biz_common/dom/event.js","biz_common/dom/class.js","common/utils.js"],function(e){
"use strict";
function t(e,t,n){
if(H){
var i={
__videoTailPlayerId__:H,
action:e,
data:t
};
"function"==typeof n&&(i.callbackId=F+Q++,G[i.callbackId]=n),window.parent.postMessage(i,document.location.protocol+"//mp.weixin.qq.com");
}else"function"!=typeof n&&(n=function(){}),z.invoke(e,t,n);
}
function n(e,t){
"function"==typeof t&&(G[e]?G[e].push(t):G[e]=[t],z.on(e,t));
}
function i(e){
"object"===_typeof(e.data)&&"string"==typeof e.data.hostEnvEvent&&G[e.data.hostEnvEvent]&&G[e.data.hostEnvEvent].forEach(function(t){
return t(e.data.res);
});
}
function o(){
return C.cpVersion("7.0.9",1,!0);
}
function a(e){
X=_extends(X,e);
}
function s(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0];
for(var t in e)e[t]&&(ot[t]=e[t]);
}
function r(){
return R.hasClass(it,"has_ad")?1:0;
}
function d(){
return _extends({
ReportWithTailAd:r()
},ot);
}
function c(){
t("handleMPPageAction",{
action:"closeAdWebview"
});
}
function l(e){
return o()||X.hasAd&&!e?void(e?X.hidePanelAd&&X.hidePanelAd():X.showTailPanel&&X.showTailPanel(X)):void c();
}
function u(){
return H?q:window.innerWidth===screen.width&&window.innerHeight===screen.height||window.innerWidth===screen.height&&window.innerHeight===screen.width;
}
function p(e){
var t;
return M.join(location.origin+"/mp/authreadtemplate?t=pages/video_tail",(t={
vid:window.cgiData.vid,
item_show_type:window.item_show_type,
idx:window.idx,
mid:window.mid,
sn:window.sn,
scene:window.scene,
appmsg_type:window.appmsg_type,
msg_title:window.msg_title,
ct:window.ct,
send_time:window.send_time,
abtest_cookie:window.abtest_cookie,
msg_daily_idx:window.msg_daily_idx,
user_uin:window.user_uin,
__biz:window.biz,
pos_type_list:9,
get_ad_after_video:1
},_defineProperty(t,D.HAS_AD_DATA_QUERY_KEY,e?1:0),_defineProperty(t,"enterid",window.enterid),
_defineProperty(t,"subscene",window.subscene),_defineProperty(t,"oriStatus",window.cgiData.ori_status),
_defineProperty(t,"hitBizUin",window.cgiData.hit_bizuin),_defineProperty(t,"hitVid",window.cgiData.hit_vid),
_defineProperty(t,"sessionid",window.sessionid),_defineProperty(t,"devicetype",window.devicetype),
_defineProperty(t,"playerType",B.getPlayerType()),_defineProperty(t,"hasSubscribed",X.hasSubscribed?1:0),
_defineProperty(t,"continueid",window.continueid+""),_defineProperty(t,"continueseq",1*M.getQuery("continueseq")||1),
t));
}
function _(e){
at=e;
}
function f(e,t,n){
if(!Y||n){
var i=p(at)+"&wcslplayerId="+t;
window.__second_open__?W({
url:i,
type:"GET",
f:"html",
success:function(t){
e.setAttribute("src",i),e.contentWindow.document.open("text/html","replace"),e.contentWindow.document.write(t),
e.contentWindow.document.close(),e.contentWindow.history.replaceState(null,null,i);
}
}):e.setAttribute("src",i),U=e,Y=!0;
}
}
function m(e){
Y||z.invoke("handleMPPageAction",{
action:"createAdWebview",
adUrl:p(e)
},function(e){
return e.err_msg.indexOf("fail")>-1?void k.report115849(40):void(Y=!0);
});
}
function w(e){
a({
showTailPanel:e.showTailPanel,
hidePanelAd:e.hidePanelAd
}),n("onMPAdWebviewStateChange",function(e){
"appear"===e.state&&(e.forceNoAd&&a({
hasAd:!1
}),l(),X.hasAd&&setTimeout(function(){
X.showAd&&X.showAd();
},10));
});
}
function v(e){
function t(){
o=!0,setTimeout(function(){
return a?void(o=!1):(s+=d,(X.canCreateTailWebview||r>=i-s)&&m(),void t());
},1e3*d);
}
function n(){
z.invoke("handleMPPageAction",{
action:"getMPVideoState"
},function(n){
n.vid===e&&(s=parseInt(n.currentTime,10)>=parseInt(n.duration,10)?0:n.currentTime,
i=n.duration,"play"===n.state&&!o&&t());
});
}
var i=void 0,o=void 0,a=!1,s=0,r=10,d=.5;
z.on("onMPVideoStateChange",function(e){
"play"===e.state?(n(),a=!1):"enterFullScreen"!==e.state&&"exitFullScreen"!==e.state&&(a=!0);
}),n();
}
function y(e){
v(e),z.on("onMPAdWebviewStateChange",function(e){
"destroy"===e.state&&(Y=!1);
});
}
function b(e){
n("onReceiveMPPageData",function(t){
e&&e(t);
});
}
function g(e,n){
U&&"adWeb"===n?U.contentWindow.postMessage({
hostEnvEvent:"onReceiveMPPageData",
res:{
data:e
}
},document.location.protocol+"//mp.weixin.qq.com"):t("handleMPPageAction",{
action:"sendMPPageData",
data:e,
sendTo:n
});
}
function h(e){
var t=u(),n=void 0;
n=r()?t?184:183:t?181:180,V.report(17149,_extends({
EventType:t?46:47
},d())),e.dataset.scene=n;
}
function P(e){
Z&&(e?(et.style.display="none",tt.style.display="",!J&&(nt.style.display="")):(et.style.display="",
tt.style.display="none",nt.style.display="none"),J=e);
}
function T(){
if(Z){
var e=u();
e&&K||!e&&$||(V.report(17149,_extends({
EventType:e?70:71
},d())),e?K=!0:$=!0);
}
}
function j(){
V.report(17149,_extends({
EventType:u()?72:73
},d()));
}
function S(){
return J;
}
function I(e){
W({
url:"/mp/videochannel_profile_page?action=check_contact&biz_username="+e.userName+"&__biz="+e.biz,
dataType:"json",
success:function(t){
var n=1===t.subscribed;
e.success&&e.success(n);
}
});
}
function E(e){
function t(){
I({
userName:e.userName,
biz:e.biz,
success:function(e){
P(e),T(),e&&g("hasSubscribed","commshareWeb");
}
});
}
O.getId("js_tail_panel_account_name").innerHTML=e.nickname,O.getId("js_tail_panel_account_avatar").src=e.headImg,
e.subscribed||P(!1),e.notBindProfileEvt?!function(){
var e=it.getElementsByClassName("js_go_profile")[0];
N.tap(e,function(){
h(e);
});
}():O.go2ProfileEvent({
$container:it,
user_name:e.userName,
beforeGo2Profile:h,
tabType:2
}),Z&&(N.on(et,"tap",function(){
var t=void 0;
j(),t=u()?"186":"185",z.invoke("addContact",{
webtype:"1",
username:e.userName,
scene:t,
scenenote:e.pageUrl||""
},function(e){
e.err_msg.indexOf("ok")>-1&&(P(!0),g("hasSubscribed","commshareWeb"));
});
}),N.bindVisibilityChangeEvt(function(e){
if(e){
var n=3;
t();
for(var i=1;n>=i;i++)setTimeout(t,200*n);
}
}));
}
function A(){
N.tap(O.getId("js_tail_share_button"),function(){
V.report(17149,_extends({
EventType:u()?53:54
},d()));
});
}
function x(e){
if(!o()||!it)return void(e.fallback&&e.fallback());
e.reportData.PlayerType=1,s(e.reportData),it.style.display="",$=!1;
var t={
Vid:ot.VideoId,
BizUin:ot.BizUserName,
msgid:ot.MsgId,
itemidx:ot.Idx,
Type:1,
ClientTime:Date.now(),
Fromid:ot.Scene,
SessionId:ot.SessionIdStr,
Device:C.isIOS?1:2
};
e.isAppMsg?V.report(12710,_extends({},ot,t,{
Step:17,
ClientTime:Date.now()
})):(V.report(17149,_extends({
EventType:65
},ot)),V.report(17149,_extends({
EventType:67
},ot)),V.report(17149,_extends({
EventType:69
},ot)),(!e.subscribed&&!L||!J&&L)&&T()),L||(E(e),A(),N.tap(O.getId("js_replay"),function(){
it.style.display="none",e.replay&&e.replay(),e.isAppMsg?V.report(12710,_extends({},ot,t,{
Step:18,
ClientTime:Date.now()
})):V.report(17149,_extends({
EventType:52
},ot));
}),L=!0);
}
var W=e("biz_wap/utils/ajax.js"),z=e("biz_wap/jsapi/core.js"),D=e("a/a_config.js"),M=e("biz_common/utils/url/parse.js"),k=e("a/a_utils.js"),C=e("biz_wap/utils/mmversion.js"),O=e("pages/utils.js"),V=e("common/comm_report.js"),N=e("biz_common/dom/event.js"),R=e("biz_common/dom/class.js"),B=e("common/utils.js"),H=M.getQuery("wcslplayerId"),q=!1,U=null,F="video_tail_callback_",Q=0,G={};
H&&window.addEventListener("message",function(e){
"object"===_typeof(e.data)&&"string"==typeof e.data.callbackId&&e.data.callbackId.startsWith(F)?(G[e.data.callbackId]&&G[e.data.callbackId](e.data.res),
delete G[e.data.callbackId]):i(e);
});
var L=!1,Y=!1,K=!1,$=!1,J=!0,X={},Z=C.isIOS&&C.cpVersion("7.0.15",1,!0);
Z=Z||C.isAndroid&&C.cpVersion("7.0.17",1,!0);
var et=O.getId("js_btn_account_subscription"),tt=O.getId("js_profile_icon"),nt=O.getId("js_subscription_success"),it=O.getId("js_video_tail_panel"),ot={
EnterId:parseInt(Date.now()/1e3,10),
ItemShowType:5
};
H&&n("onWcSlPlayerFullscreenChange",function(e){
q=e.state,"string"==typeof e.padding&&(document.body.style.padding=e.padding);
});
var at=!1;
return{
createTailWebview:m,
initEvent4TailWebview:w,
listenAndCreateTailWebview:v,
onReceiveMPPageData:b,
setTailOpts:a,
showTailPanel:l,
sendMPPageData:g,
handleTailWebviewState:y,
closeTailWebview:c,
initProfile:E,
initWebTailPanel:x,
isFullScreen:u,
getSubscribedStatus:S,
reportSubscribeBtnExpose:T,
changeSubscribeStatus:P,
getSubscribedData:I,
supportTailPanel:o,
getReportData:d,
initShareBtnReport:A,
setReportData:s,
setHasAdData4WcSlPlayer:_,
initTailIframe4WcSlPlayer:f,
emitHostEnvEvent4WcSlPlayer:i,
sendMessageToHostEnv:t
};
});function _typeof(e){
return e&&"undefined"!=typeof Symbol&&e.constructor===Symbol?"symbol":typeof e;
}
function _toConsumableArray(e){
if(Array.isArray(e)){
for(var t=0,o=Array(e.length);t<e.length;t++)o[t]=e[t];
return o;
}
return Array.from(e);
}
define("a/web_compt_ad.js",["biz_wap/utils/mmversion.js","common/utils.js","a/a_config.js","biz_common/utils/url/parse.js","a/a_utils.js","biz_common/dom/offset.js","biz_wap/utils/ajax.js","a/appdialog_confirm.js","biz_wap/jsapi/core.js"],function(e){
"use strict";
function t(e,t){
return e+" | "+t;
}
function o(e,t){
if(!e)return null;
var o=t.aInfo;
console.log("广告 "+o.aid+"使用了 web 组件渲染模式");
var a=document.createElement("wx-ad");
a.className="web_compt_ad",a.scrolling="no",a.createComptTime=Date.now();
var i={
adData:o,
pageData:_(t,e,a.createComptTime)
};
return a.innerHTML='<template slot="renderData">'+JSON.stringify(i).htmlEncodeLite()+"</template>",
e.appendChild(a),n.isIOS&&(a.style.width="1px",a.style.minWidth="100%"),d.report128729(0),
a;
}
function a(){
this.aInfoMap={};
}
var n=e("biz_wap/utils/mmversion.js"),i=e("common/utils.js"),r=e("a/a_config.js"),s=e("biz_common/utils/url/parse.js"),d=e("a/a_utils.js"),p=e("biz_common/dom/offset.js"),c=e("biz_wap/utils/ajax.js"),m=e("a/appdialog_confirm.js"),u=e("biz_wap/jsapi/core.js"),l=!!s.getQuery("mock")||!!s.getQuery("rtx"),f=r.AD_POS,g=window.__report,w=document.getElementById("page-content"),y=document.getElementById("js_bottom_ad_area"),_=function(e,t,o){
var a="8"===window.item_show_type&&i.isNativePage(),n="";
return e.aInfo.pos_type===f.POS_MID&&(n=t&&t.dataset&&t.dataset.category_id_list),
{
biz:window.biz,
uin:window.uin,
scene:window.scene,
source:window.source,
idx:window.idx,
mid:window.mid,
isSg:window.isSg,
userUin:window.user_uin,
sn:window.sn,
appmsgid:window.appmsgid,
sendTime:window.send_time||"",
passTicket:decodeURIComponent(window.pass_ticket),
globalAdDebug:l,
bodyScrollTop:i.getScrollTop(),
contentOffsetHeight:w?w.offsetHeight:0,
adOffsetTop:p.getOffset(t).offsetTop,
screenHeight:i.getInnerHeight(),
midCategoryIdList:n,
heightWidthRate:e.heightWidthRate,
createComptTime:o,
skin:a?"black":"white"
};
};
return a.prototype.config=function(e){
this.configData=e;
},a.prototype.handleAd=function(){
var e=arguments.length<=0||void 0===arguments[0]?[]:arguments[0],t=arguments.length<=1||void 0===arguments[1]?0:arguments[1],o=0,a=this;
this.midAdDataCount=t,this.webComptAdInfos=e,e.forEach(function(e){
return a.aInfoMap[e.aid]={
aInfo:e
},e.pos_type===f.POS_MID?(a.initMidAd(a.aInfoMap[e.aid],o),void o++):void(e.pos_type===f.POS_BOTTOM&&a.initBottomAd(a.aInfoMap[e.aid]));
});
var n=document.getElementById("js_article");
n&&n.addEventListener("click",function(){
for(var e in a.aInfoMap)Object.prototype.hasOwnProperty.call(a.aInfoMap,e)&&a.aInfoMap[e].webComptEle&&a.aInfoMap[e].webComptEle.onClickOutside&&a.aInfoMap[e].webComptEle.onClickOutside();
});
},a.prototype.initMidAd=function(e,t){
var a=e.aInfo;
this.configData.insertAutoAdElement(a,!1,t,this.midAdDataCount);
var n=document.getElementsByTagName("mpcpc")[t];
if(n){
var i=o(n,this.aInfoMap[a.aid]);
d.report128729(1),this.aInfoMap[a.aid].webComptEle=i,this.addTagListeners(e,i),g&&g(125);
}
},a.prototype.initBottomAd=function(e){
var t=e.aInfo,a=o(y,this.aInfoMap[t.aid]);
d.report128729(2),this.aInfoMap[t.aid].webComptEle=a,this.addTagListeners(e,a);
},a.prototype.warpProxyCallback=function(e,t,o){
return function(){
for(var a=arguments.length,n=Array(a),i=0;a>i;i++)n[i]=arguments[i];
n=o&&"function"==typeof o?o.apply(void 0,_toConsumableArray(n)):n[0],t.data&&"openUrlWithExtraWebview"===t.data.methodName&&-1===n.err_msg.indexOf("ok")&&(location.href=t.data.args.url),
e.proxyCallback({
proxyId:t.proxyId,
data:n
});
};
},a.prototype.addTagListeners=function(e,o){
var a=this,n=this,i=e.aInfo;
o.addEventListener("ready",function(){
o.setData({
pageData:a.getPageData(e),
adData:i
});
}),o.addEventListener("proxy",function(a){
var i=a.detail;
if(i)if("request"===i.proxyType)n.commonRequest(i.data,n.warpProxyCallback(o,i));else if("appDialogConfirm"===i.proxyType)m({
app_name:i.data.app_name,
app_img_url:i.data.icon_url,
onOk:n.warpProxyCallback(o,i,function(){
return{
err_msg:"appDialogConfirm:yes"
};
}),
onCancel:n.warpProxyCallback(o,i,function(){
return{
err_msg:"appDialogConfirm:cancel"
};
})
});else if("jsapi"===i.proxyType){
var s=function(){
var a=n.checkApiInvokeValid(e,i.data);
if("string"==typeof a)return n.warpProxyCallback(o,i,function(){
return{
err_msg:a
};
})(),{
v:void 0
};
try{
"on"===i.data.methodType?u[i.data.methodType](i.data.methodName,n.warpProxyCallback(o,i)):u[i.data.methodType](i.data.methodName,i.data.args,n.warpProxyCallback(o,i));
}catch(s){
console.error(s),n.warpProxyCallback(o,i,function(){
return{
err_msg:t(r.INVALID_METHOD_TYPE_MSG_PREFIX,i.data.methodType)
};
})();
}
}();
if("object"===("undefined"==typeof s?"undefined":_typeof(s)))return s.v;
}else console.error("unknow webCompt proxy:",i);else console.error("tag proxy without proxyData:",a);
});
},a.prototype.checkApiInvokeValid=function(e,o){
if(!e)return"Invalid aid";
var a=e.aInfo,n=o.methodName;
return-1===r.AD_JSAPI_WHITE_LIST.indexOf(n)?t(r.INVALID_METHOD_NAME_MSG_PREFIX,n):"addContact"!==n&&"profile"!==n||a&&a.biz_info&&o.args.username===a.biz_info.user_name?!0:t(r.INVALID_ARGS_MSG_PREFIX,"Invalid biz username");
},a.prototype.commonRequest=function(e,o){
var a=e||{},n=a.path&&d.checkRequestUrlAllowed(a.path);
return n?void c({
type:a.requestType,
url:s.join(a.path,a.requestQuery||{}),
data:a.requestBody||{},
mayAbort:!0,
success:function(e){
o({
err_msg:"request:success",
response:e
});
},
error:function(e,t){
var a={};
try{
a={
readyState:e.readyState,
response:e.response,
responseText:e.responseText,
responseType:e.responseType,
responseURL:e.responseURL,
responseXML:e.responseXML,
status:e.status,
statusText:e.statusText,
timeout:e.timeout
};
}catch(n){
console.error(n);
}
o({
err_msg:"request:error",
xhr:a,
err_info:t
});
}
}):void o({
err_msg:t(r.INVALID_REQ_PATH_MSG_PREFIX,a.path)
});
},a.prototype.getPageData=function(e){
var t="8"===window.item_show_type&&i.isNativePage(),o=e.webComptEle.parentNode,a="";
return e.aInfo.pos_type===f.POS_MID&&(a=o&&o.dataset&&o.dataset.category_id_list),
{
biz:window.biz,
uin:window.uin,
scene:window.scene,
source:window.source,
idx:window.idx,
mid:window.mid,
isSg:window.isSg,
userUin:window.user_uin,
sn:window.sn,
appmsgid:window.appmsgid,
sendTime:window.send_time||"",
passTicket:decodeURIComponent(window.pass_ticket),
globalAdDebug:l,
bodyScrollTop:i.getScrollTop(),
contentOffsetHeight:w?w.offsetHeight:0,
adOffsetTop:p.getOffset(e.webComptEle).offsetTop,
screenHeight:i.getInnerHeight(),
midCategoryIdList:a,
heightWidthRate:e.heightWidthRate,
createComptTime:e.webComptEle.createComptTime,
skin:t?"black":"white"
};
},a;
});define("a/appdialog_confirm.js",["widget/wx_profile_dialog_primary.css","a/a_utils.js","common/utils.js","biz_wap/jsapi/core.js","biz_common/utils/url/parse.js","biz_common/tmpl.js","biz_common/dom/event.js","a/appdialog_confirm.html.js"],function(o){
"use strict";
o("widget/wx_profile_dialog_primary.css");
var e=o("a/a_utils.js"),n=o("common/utils.js"),i=o("biz_wap/jsapi/core.js"),a=o("biz_common/utils/url/parse.js"),m=o("biz_common/tmpl.js"),c=o("biz_common/dom/event.js"),s=o("a/appdialog_confirm.html.js"),t=function(o){
if(e.isVideoSharePageOnlyAd()||n.isNativePage()||a.getQuery("get_ad_after_video"))return void i.invoke("confirmDialog",{
title:"是否立即下载该应用",
contentDesc:o.app_name,
confirmText:"下载",
cancelText:"取消",
msgIconUrl:o.app_img_url,
msgIconWidth:50,
msgIconHeight:50
},function(e){
e.err_msg.indexOf("confirmDialog:ok")>-1?o.onOk&&o.onOk():o.onCancel&&o.onCancel();
});
var t=document.createElement("div");
t.innerHTML=m.tmpl(s,o,!1),document.body.appendChild(t),c.on(t.getElementsByClassName("js_ok")[0],"click",function(){
o.onOk&&o.onOk(),document.body.removeChild(t);
}),c.on(t.getElementsByClassName("js_cancel")[0],"click",function(){
o.onCancel&&o.onCancel(),document.body.removeChild(t);
});
};
return t;
});define("biz_common/utils/get_para_list.js",[],function(){
"use strict";
function e(t,r){
if(!t||1!==t.nodeType)return!1;
for(var i=0;i<t.children.length;i++)if(-1!==n.indexOf(t.children[i].tagName)||r.getSpan&&"SPAN"===t.children[i].tagName&&e(t.children[i],r))return!0;
}
function t(e,t){
for(var r=0;r<i.length;r++)if(e.className.indexOf(i[r])>-1)return!0;
return t.ignoreFlexChildren&&"flex"===e.style.display||t.ignoreNotWriteableChildren&&("false"===e.getAttribute("contenteditable")||1===e.childNodes.length&&"false"===e.childNodes[0].getAttribute("contenteditable"))?!0:a.indexOf(e.tagName)>-1;
}
function r(n,i){
var a=n.children;
if(!a.length)return a;
for(var l,d=[],o=0;o<a.length;o++)l=a[o],l.isWrapper=void 0,i&&i.isMarkNode&&i.isMarkNode(l)||(e(l,i)&&!t(l,i)?(d=d.concat(r(l,i)),
i.getNestedStructure&&(l.isWrapper=!0,d.push(l))):d.push(l));
return d;
}
var n=["P","DIV","SECTION","LI","H1","H2","H3","H4","H5","H6","TABLE","WX-VIEW"],i=["js_product_container","js_blockquote_wrap"],a=["BLOCKQUOTE"];
return r.paragraphStartIdx=1e6,r;
});define("biz_common/utils/comm_report.js",[],function(){
"use strict";
var r={
web:{
report:"/cgi-bin/webreport"
},
wap:{
report:"/mp/wapcommreport"
}
},e=function(r,e){
return e=JSON.parse(JSON.stringify(e)),e.log_id=r,console.log("[comm_report] reportjson: ",e),
JSON.stringify(e);
},o=!1,t=[],n={
web:{
report:function(o,t,n,s){
s=s||{},o.post({
url:r.web.report,
data:{
reportjson:e(t,n)
},
async:s.async,
success:s.success,
error:s.error
});
},
leaveReport:function(r,e,s){
if(t.push([r,e,s]),!o){
o=!0;
var c=!1,p=function(){
c||(c=!0,t.forEach(function(r){
n.web.report(r[0],r[1],r[2]);
}));
};
window.addEventListener("beforeunload",p,!1),window.addEventListener("unload",p,!1);
}
}
},
wap:{
report:function(o,t,n,s){
s=s||{},o({
type:"POST",
dataType:"json",
url:r.wap.report,
data:{
reportjson:e(t,n)
},
async:s.async,
success:s.success,
error:s.error
});
}
}
};
return{
report:function(r,e,o,t,s){
n[r].report(e,o,t,s);
},
leaveReport:function(r,e,o,t){
n[r].leaveReport(e,o,t);
},
getUrl:function(e,o){
return r[e][o];
},
getData:function(r,o,t){
var n=e(r,o);
return t&&(n=encodeURIComponent(n)),"reportjson="+n;
}
};
});