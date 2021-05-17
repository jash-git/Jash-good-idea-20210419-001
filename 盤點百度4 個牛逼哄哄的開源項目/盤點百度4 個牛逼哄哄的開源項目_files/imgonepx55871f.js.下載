define("biz_common/utils/cookie.js",[],function(){
"use strict";
var e={
get:function(e){
if(""==e)return"";
var t=new RegExp(e+"=([^;]*)"),n=document.cookie.match(t);
return n&&n[1]||"";
},
set:function(e,t,n){
var o=new Date;
return o.setDate(o.getDate()+(n||1)),n=o.toGMTString(),document.cookie=e+"="+t+";expires="+n,
!0;
}
};
return e;
});define("appmsg/open_url_with_webview.js",["biz_wap/jsapi/core.js"],function(e){
"use strict";
var r=e("biz_wap/jsapi/core.js"),n=-1!=navigator.userAgent.indexOf("WindowsWechat"),i=function(e,i){
if(n)return location.href=e,!1;
i=i||{};
var o=i.sample||0;
o*=1e3;
var t=window.user_uin||0,s=0!==t&&Math.floor(t/100)%1e3<o;
return s?void r.invoke("openUrlWithExtraWebview",{
url:e,
openType:i.openType||1,
scene:i.scene||"",
bizUsername:i.user_name||""
},function(e){
e&&"openUrlWithExtraWebview:ok"===e.err_msg?i.resolve&&i.resolve():i.reject&&i.reject();
}):void(i.reject&&i.reject());
};
return i;
});var _extends=Object.assign||function(e){
for(var n=1;n<arguments.length;n++){
var i=arguments[n];
for(var t in i)Object.prototype.hasOwnProperty.call(i,t)&&(e[t]=i[t]);
}
return e;
};
define("appmsg/album_keep_read.js",["page/appmsg_new/mod/album_read.css","biz_common/dom/event.js","biz_common/dom/class.js","pages/mod/bottom_modal.js","biz_wap/utils/openUrl.js","pages/utils.js","biz_wap/utils/ajax.js","common/comm_report.js","common/utils.js","biz_common/dom/offset.js","biz_wap/utils/wapsdk.js"],function(e){
"use strict";
function n(e,n){
v.jsmonitor({
id:223326,
key:e,
value:n
});
}
function i(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0];
b.report(21277,_extends({},x,e));
}
function t(){
function e(){
if(!t){
var e=w.getOffset(h).offsetTop,o=f.getScrollTop();
o+f.getInnerHeight()>=e+a&&e+a>=o&&(i({
ActionType:1
}),n(11),t=!0);
}
}
var t=void 0,a=h.offsetHeight/2;
f.bindDebounceScrollEvent(e),e();
}
function a(){
var e=window.appmsg_album_info;
if(e.link){
var n=e.link.replace("#wechat_redirect","&subscene=159&subscene="+window.source+"&scenenote="+encodeURIComponent(window.location.href)+"&nolastread=1#wechat_redirect");
_.openUrlWithExtraWebview(n.htmlDecode());
}
}
function o(e){
e&&c.on(e,"click","."+y.itemClassName,function(e){
var n=e.delegatedTarget;
if(!u.hasClass(n,"album_read_directory_current")){
var t=void 0;
t=n.dataset.url.includes("#")?n.dataset.url.replace("#",T+"&scene=190#"):n.dataset.url+(T+"&scene=190"),
i({
ActionType:5,
Url:t
}),p.jumpUrl(t,!0),u.addClass(n,"album_read_directory_disabled");
}
});
}
function s(){
var e=document.createElement("div"),n=document.createElement("span");
return n.innerHTML="#"+window.appmsg_album_info.title,e.appendChild(n),e.innerHTML;
}
function r(e){
g({
type:"GET",
url:"/mp/appmsgalbum?action=paging&__biz="+window.biz+"&album_id="+y.albumId+"&cur_msgid="+y.msgid+"&cur_itemidx="+y.idx+"&count="+y.pageCount,
timeout:5e3,
dataType:"json",
success:function(n){
n.base_resp&&0===n.base_resp.ret&&e(n.getalbum_resp);
},
error:function(){
console.log("[error]");
}
});
}
function l(){
function e(e){
var n=arguments.length<=1||void 0===arguments[1]?!1:arguments[1],i=arguments.length<=2||void 0===arguments[2]?!0:arguments[2],t=document.createDocumentFragment();
if(_)if(n){
h=1;
for(var a=0;a<e.length;a++)if(e[a].msgid.toString()===y.msgid.toString()&&e[a].itemidx.toString()===y.idx.toString()){
h=a;
break;
}
e.forEach(function(e,n){
e.index=p?c-(n-h):c+(n-h);
});
}else e.forEach(i?function(e,n){
e.index=p?v.index-n-1:v.index+n+1;
}:function(n,i){
n.index=p?w.index+(e.length-i):w.index-(e.length-i);
});
return e.forEach(function(e){
var n=document.createElement("div");
if(u.addClass(n,y.itemClassName),e.msgid.toString()===window.mid.toString()&&e.itemidx.toString()===window.idx.toString()?u.addClass(n,"album_read_directory_current"):1===e.user_read_status&&u.addClass(n,"album_read_directory_disabled"),
n.innerText=_?e.index+"."+e.title:e.title,n.setAttribute("data-url",e.url),e.is_paid){
var i="已付费";
n.innerHTML+='<span class="wx_icon_pay_tag wx_icon_pay_tag_paid">'+i+"</span>";
}else if(e.is_pay_subscribe){
var a="付费";
n.innerHTML+='<span class="wx_icon_pay_tag">'+a+"</span>";
}
t.appendChild(n);
}),t;
}
function t(e){
1*e.reverse_continue_flag||(b=!1),1*e.continue_flag||(f=!1);
}
var l=document.createElement("div");
l.style.position="relative";
var d=[],c=void 0,_=void 0,p=void 0,b=!0,f=!0,w=void 0,v=void 0,h=1,x={
extClass:"album_read_directory",
hasBtn:!0,
btnSlot:'<div id="js_topic_detail" class="weui-btn__word-wrp">\n                  <span class="weui-btn__word">详情</span>\n                  <i class="weui_right_arrow"></i>\n                </div>',
title:s(),
btnClickCb:function(){
i({
ActionType:6
}),n(15),a();
},
cb:function(){
r(function(n){
j.hideLoading(),p=n.base_info.is_reverse,c=n.base_info.cur_article_num,_=c?1:0,l.appendChild(e(n.article_list,!0)),
w=n.article_list[0],v=n.article_list[n.article_list.length-1],t(n),f||j.showEndLine();
var i=l.childNodes[h];
setTimeout(function(){
i.offsetTop+i.clientHeight>j.contentAreaWrp.clientHeight&&j.scrollTo(0,l.offsetHeight);
},200);
});
},
onShow:function(){
i({
ActionType:4
}),n(14);
},
onPullUpLoad:function(){
f&&(j.showPullUpLoading(),g({
type:"GET",
url:"/mp/appmsgalbum?action=paging&__biz="+window.biz+"&album_id="+y.albumId+"&begin_msgid="+v.msgid+"&begin_itemidx="+v.itemidx+"&count="+y.pageCount,
timeout:5e3,
dataType:"json",
success:function(n){
j.hidePullUpLoading();
var i=n.base_resp&&1*n.base_resp.ret;
if(0===i){
var a=n.getalbum_resp.article_list;
t(n.getalbum_resp),l.appendChild(e(a,!1,!0)),d=d.concat(a),j.finishPullUpLoad(),
v=d[d.length-1],1*n.getalbum_resp.continue_flag||j.showEndLine();
}
},
error:function(){}
}));
},
onPullDownLoad:function(){
b&&(j.showPullDownLoading(),g({
type:"GET",
url:"/mp/appmsgalbum?action=paging&__biz="+window.biz+"&album_id="+y.albumId+"&begin_msgid="+w.msgid+"&begin_itemidx="+w.itemidx+"&count="+y.pageCount+"&isbackward=1",
timeout:5e3,
dataType:"json",
success:function(n){
j.hidePullDownLoading();
var i=n.base_resp&&1*n.base_resp.ret;
if(0===i){
var a=n.getalbum_resp.article_list,o=n.getalbum_resp.continue_flag;
n.getalbum_resp.continue_flag=n.getalbum_resp.reverse_continue_flag,n.getalbum_resp.reverse_continue_flag=o,
t(n.getalbum_resp);
var s=e(a,!1,!1),r=l.firstChild;
l.insertBefore(s,r),d=a.concat(d),j.scrollTo(0,r.offsetTop-69),j.finishPullDownLoad(),
w=d[0];
}
},
error:function(){}
}));
}
};
window.appmsg_album_info.size<=4&&(x.top=screen.height/2-(screen.height-window.innerHeight)+"px"),
j=new m(l,x),j.showLoading(),j.show(),o(l);
}
function d(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0],t=document.getElementById("js_album_directory");
c.on(t,"click",function(){
j?j.show():l();
});
var a=document.getElementById("js_album_prev"),o=document.getElementById("js_album_next");
e.pre_article_link?c.on(a,"click",function(){
var t=void 0;
i({
ActionType:2,
SubActionType:1
}),n(12),t=e.pre_article_link.includes("#")?e.pre_article_link.replace("#",T+"&scene=189#"):e.pre_article_link+(T+"&scene=189"),
location.href=t.replace(/&amp;/g,"&");
}):a.parentNode.removeChild(a),e.next_article_link?c.on(o,"click",function(){
var t=void 0;
i({
ActionType:2,
SubActionType:2
}),n(13),t=e.next_article_link.includes("#")?e.next_article_link.replace("#",T+"&scene=189#"):e.next_article_link+(T+"&scene=189"),
location.href=t.replace(/&amp;/g,"&");
}):o.parentNode.removeChild(o);
}
e("page/appmsg_new/mod/album_read.css");
var c=e("biz_common/dom/event.js"),u=e("biz_common/dom/class.js"),m=e("pages/mod/bottom_modal.js"),_=e("biz_wap/utils/openUrl.js"),p=e("pages/utils.js"),g=e("biz_wap/utils/ajax.js"),b=e("common/comm_report.js"),f=e("common/utils.js"),w=e("biz_common/dom/offset.js"),v=e("biz_wap/utils/wapsdk.js"),h=document.getElementById("js_album_keep_read"),y={
link:window.appmsg_album_info.link,
albumId:window.appmsg_album_info.id,
msgid:window.mid,
idx:window.idx,
pageCount:10,
itemClassName:"album_read_directory_item"
},x={
MsgId:1*y.msgid,
ItemIdx:1*y.idx,
BizUin:window.biz,
Itemshowtype:1*window.item_show_type,
SessionId:window.sessionid,
EnterId:1*window.enterid,
Scene:1*window.source,
SubScene:1*window.subscene,
Albumid:y.albumId,
Albumtype:window.appmsg_album_info.type,
Title:window.appmsg_album_info.title
},j=void 0,T="&cur_album_id="+y.albumId;
return{
init:function(e){
h&&(e.pre_article_link||e.next_article_link)&&(document.getElementById("js_album_keep_read_title").innerHTML=window.appmsg_album_info.title,
document.getElementById("js_album_keep_read_size").innerHTML=window.appmsg_album_info.size,
document.getElementById("js_album_keep_read_pre_title").innerHTML=e.pre_article_title||"",
document.getElementById("js_album_keep_read_next_title").innerHTML=e.next_article_title||"",
h.style.display="block",d(e),t());
}
};
});define("appmsg/more_read.js",["biz_common/utils/string/html.js","biz_common/tmpl.js","biz_wap/utils/ajax.js","appmsg/more_read_tpl.html.js","biz_wap/utils/openUrl.js","biz_common/dom/event.js","biz_wap/utils/jsmonitor_report.js","common/utils.js"],function(n){
"use strict";
function i(n){
for(var i=r.getInnerHeight(),e=document.documentElement.clientWidth||window.innerWidth,t=document.body.scrollHeight||document.body.offsetHeight,s=document.body.scrollTop||document.documentElement.scrollTop,m=[],a=0;a<l.length;a++){
var w=[l[a].bizuin||window.biz||"",l[a].mid||"",l[a].idx||""].join("_");
m.push(w);
}
m=m.join("#");
var p=c[n.index].getBoundingClientRect(),h="fans_read_cnt="+l[n.index].fans_read_cnt,g={
act:n.action||0,
bizuin:window.biz||"",
msgid:window.mid||"",
idx:window.idx||"",
scene:window.source||"",
sub_scene:window.subscene||"",
get_a8_key_scene:window.ascene||"",
screen_height:i,
screen_width:e,
screen_num:Math.ceil(t/i),
action_screen_num:Math.ceil((p.top+p.height+s)/i),
start_time_ms:_,
action_time_ms:Date.now(),
more_msg:m,
a_bizuin:l[n.index].bizuin||window.biz||"",
a_msgid:l[n.index].mid||"",
a_idx:l[n.index].idx||"",
rank:n.index+1,
tip:h,
session_id:u
};
o({
url:"/mp/appmsgreport?action=more_read",
type:"POST",
data:g,
timeout:2e3,
async:!1,
mayAbort:!0
});
var b=1===n.action?4:5;
d.setSum(110809,b,1);
}
function e(){
if(l){
for(var n=0,t=r.getInnerHeight(),o=0;o<c.length;o++)if(c[o].dataset.show)n++;else{
var s=c[o].getBoundingClientRect();
s.top+s.height<t&&(c[o].dataset.show=1,i({
action:1,
index:o
}));
}
n>=c.length&&a.off(window,"scroll",e);
}
}
n("biz_common/utils/string/html.js");
var t=n("biz_common/tmpl.js"),o=n("biz_wap/utils/ajax.js"),s=n("appmsg/more_read_tpl.html.js"),m=n("biz_wap/utils/openUrl.js"),a=n("biz_common/dom/event.js"),d=n("biz_wap/utils/jsmonitor_report.js"),r=n("common/utils.js"),l=null,c=null,_=Date.now(),u=""+_+"_"+Math.random().toString(36).substring(2);
return a.on(window,"scroll",e),function(n,e){
l=e,n.innerHTML=t.tmpl(s,{
list:l
},!1),c=n.getElementsByClassName("more_read_link");
for(var o=0;o<c.length;o++)a.on(c[o],"click",function(n){
return function(){
window.__second_open__?m.openUrlWithExtraWebview(l[n].link.htmlDecode()):window.location.href=l[n].link.htmlDecode(),
i({
action:2,
index:n
});
};
}(o));
n.style.display="";
};
});var _extends=Object.assign||function(e){
for(var t=1;t<arguments.length;t++){
var n=arguments[t];
for(var o in n)Object.prototype.hasOwnProperty.call(n,o)&&(e[o]=n[o]);
}
return e;
};
define("appmsg/comment.js",["biz_wap/ui/weui.js","biz_common/utils/string/html.js","biz_common/utils/wxgspeedsdk.js","appmsg/comment_report.js","biz_wap/utils/device.js","biz_common/utils/url/parse.js","biz_wap/jsapi/core.js","common/utils.js","biz_common/dom/event.js","biz_wap/utils/ajax.js","biz_common/tmpl.js","biz_wap/utils/fakehash.js","appmsg/log.js","appmsg/comment/comment_tpl.html.js","appmsg/comment/comment_write.html.js","appmsg/comment/comment_write_old.html.js","pages/utils.js","biz_wap/utils/mmversion.js","common/comm_report.js","appmsg/set_font_size.js","biz_wap/utils/jsmonitor_report.js","common/keyboard.js","appmsg/comment/comment_write_dialog/comment_write_dialog.js","appmsg/comment/comment_list/comment_list.js","appmsg/comment/comment_dialog/comment_dialog.js","appmsg/comment/comment_input/comment_input.js","appmsg/comment/comment_length.js","pages/scrollY.js","appmsg/comment/comment_report.js","pages_new/common_share/video/store.js"],function(e){
"use strict";
e("biz_wap/ui/weui.js"),e("biz_common/utils/string/html.js");
var t=e("biz_common/utils/wxgspeedsdk.js"),n=e("appmsg/comment_report.js"),o=e("biz_wap/utils/device.js"),i=e("biz_common/utils/url/parse.js"),m=e("biz_wap/jsapi/core.js"),s=e("common/utils.js"),a=e("biz_common/dom/event.js"),c=e("biz_wap/utils/ajax.js"),d=e("biz_common/tmpl.js"),r=e("biz_wap/utils/fakehash.js"),l=e("appmsg/log.js"),p=e("appmsg/comment/comment_tpl.html.js"),_=e("appmsg/comment/comment_write.html.js"),u=e("appmsg/comment/comment_write_old.html.js"),w=e("pages/utils.js"),y=e("biz_wap/utils/mmversion.js"),g=e("common/comm_report.js"),f=e("appmsg/set_font_size.js"),I=e("biz_wap/utils/jsmonitor_report.js"),C=e("common/keyboard.js"),b=e("appmsg/comment/comment_write_dialog/comment_write_dialog.js"),j=e("appmsg/comment/comment_list/comment_list.js"),h=e("appmsg/comment/comment_dialog/comment_dialog.js"),v=e("appmsg/comment/comment_input/comment_input.js"),k=e("appmsg/comment/comment_length.js"),L=e("pages/scrollY.js"),D=e("appmsg/comment/comment_report.js"),R=D.report22214,x=!window.isPaySubscribe||window.isPaySubscribe&&window.isPaid,F=s.getInnerHeight(),T=k.getLimit("comment"),S=0;
try{
S=1*window.atob(window.biz);
}catch(P){}
var z={
BizUin:S,
BizUinStr:window.biz||"",
AppMsgId:window.parseInt(window.mid,10)||0,
ItemIdx:window.parseInt(window.idx,10)||0,
ItemShowType:window.parseInt(window.item_show_type,10)||0,
SessionIdStr:window.sessionid||"",
EnterId:window.parseInt(window.enterid,10)||0,
Scene:window.parseInt(window.source,10)||0,
SubScene:window.parseInt(window.subscene,10)||0
},E={
bizuin:S,
msgid:window.parseInt(window.mid,10)||0,
itemidx:window.parseInt(window.idx,10)||0,
scene:window.parseInt(window.source,10)||0
},A=!1,B=void 0,M=void 0,N=void 0,O=void 0,W=!1,H=[],U={},K=0,G=Date.now(),V=[],q=null,Y=!1,J=!1,Q=!1,X={
commentCount:"",
scrollCount:0,
nickName:"我",
headImg:"",
offset:0,
commentId:window.comment_id,
onlyFansCanComment:0,
onlyFansDaysCanComment:0,
isFans:0,
isFansDays:0,
replyFlag:0,
reportData:{
scene:0,
idkey:"",
moreList:27,
repeatList:25,
errList:18,
handleList:26,
addCommentErr:19,
errComment:18,
repeatContent:24,
repeatContentID:23
},
contentIDs:[],
canC2CReply:!1,
cmtDialog:null,
cmtList:null,
myList:null
},Z=100,$=location.href,et=y.is_wxwork,tt=o.os.pc&&!et,nt="comment_editing",ot="my_comment_empty_data",it=navigator.userAgent.indexOf("MicroMessenger")>-1,mt=w.getId("js_cmt_area"),st=$.indexOf("vconsole=1")>0||document.cookie&&document.cookie.indexOf("vconsole_open=1")>-1,at=w.getId("activity-name")||"";
at&&(at=w.trim(at.innerText)||""),window.pageCommentReportData&&window.pageCommentReportData.idkey&&(st&&console.log("init reportData"),
X.reportData=window.pageCommentReportData),"undefined"!=typeof window.comment_id?X.commentId=window.comment_id:window.cgiData&&"undefined"!=typeof window.cgiData.comment_id&&(X.commentId=window.cgiData.comment_id),
it||(mt&&(mt.style.display="none"),X.commentId=0),st&&console.info("[图文评论] 评论ID:",X.commentId);
var ct=function(){
return y.isWechat?y.isInMiniProgram?0:C.canUseKeyboard?2:(y.isIOS||y.isAndroid)&&(y.gtVersion("7.0.8")||s.isNativePage())?2:0:0;
}(),dt=function(e,t){
e&&(e.style.display=t||"block");
},rt=function(e){
e&&(e.style.display="none");
},lt=function(e){
if(!e)return!1;
var t=s.getScrollTop(),n=e.offsetTop;
return t+F>n&&n>=t;
},pt=function(e,n){
Math.random()<.999||(t.saveSpeeds({
uin:window.uin,
pid:"https:"===window.location.protocol?18:9,
speeds:[{
sid:29,
time:e
},{
sid:30,
time:n
}]
}),t.send());
},_t=function(e){
var t=arguments.length<=1||void 0===arguments[1]?"":arguments[1];
if("undefined"!=typeof e)if(X.reportData.idkey)I.setSum(X.reportData.idkey,e,1);else{
var n=new Image,o=Math.random();
n.src="/mp/jsreport?key="+e+"&content="+t+"&r="+o;
}
},ut=function(){
Array.prototype.forEach.call(w.getByClass("js_more_reply"),function(e){
var t=e.dataset.myId;
-1===V.indexOf(t)&&lt(e)&&(g.report(19462,_extends({
PersonalCommentId:parseInt(t,10)||0,
CommentId:parseInt(X.commentId,10)||0,
actiontype:1,
wording:"余下N条",
number:parseInt(e.dataset.num,10)||0,
devicetype:tt?1:2
},E)),V.push(t));
});
},wt=function(){
2>K||[X.myList.getItemList(),X.cmtList.getItemList()].forEach(function(e,t){
var n=X[t?"cmtList":"myList"];
e.some(function(e){
if(!e.isExposed){
var o=e.getBoundingClientRect(),i=.5*o.height;
if(o.bottom>i&&o.top<F-i){
e.isExposed=!0;
var m=e.dataset,s={
PersonalCommentId:1*m.myId,
ReplyId:0,
IsPopup:0,
IsReplyOther:0,
CommentReplyType:t?1:2
};
if(m.replyId){
var a=n.getData({
type:"reply",
contentId:m.contentId,
replyId:1*m.replyId
});
s.ReplyId=a.reply_id,s.IsReplyOther=a.to_nick_name&&a.to_content?1:0;
}
R(s);
}else if(o.top>=F-i)return!0;
}
return!1;
});
});
},yt=function(){
M||(M=!0,new n({
comment_id:X.commentId,
appmsgid:window.appmsgid,
idx:window.idx,
item_show_type:window.item_show_type||0,
biz:window.biz
}),ut());
},gt=function Bt(){
try{
lt(U.loading)&&W&&(I.setLogs({
id:28307,
key:45,
value:1,
lc:1,
log0:""
}),a.off(window,"scroll",Bt));
}catch(e){
console.error(e);
}
},ft=function(){
X.myList.showAll(),wt(),U.mylistFolder&&(U.mylistFolder.parentNode.removeChild(U.mylistFolder),
U.mylistFolder=null);
},It=function(){
var e=!0,t=!0,n=!1,o=null,i=null,m=null,s=function(e){
e&&window.scrollTo(0,e.getBoundingClientRect().top+w.getScrollTop()-6);
};
return function(a,c){
if(e&&window.goContentId&&!c&&a)if(!window.onload_endtime||new Date-window.onload_endtime<1e3){
if(J&&(null===o&&(o=null!==X.myList.getData({
contentId:window.goContentId
})),o))return void("none"!==mt.style.display&&(ft(),s(""!==window.goReplyId?X.myList.getReply(window.goContentId,1*window.goReplyId):X.myList.getComment(window.goContentId)),
e=!1));
Y&&(null===i&&(m=X.cmtList.getData({
contentId:window.goContentId
}),i=null!==m),i&&(t&&""!==window.goReplyId&&(m.reply_new.reply_total_cnt&&m.reply_new.reply_total_cnt!==m.reply_new.reply_list.length?X.cmtDialog.showDialog(X.cmtList.getData({
contentId:window.goContentId
}),1*window.goReplyId):n=!0,t=!1),J&&(s(n?X.cmtList.getReply(window.goContentId,1*window.goReplyId):X.cmtList.getComment(window.goContentId)),
e=!1)));
}else e=!1;
};
}(),Ct=function(e,t){
X.onlyFansDaysCanComment&&0===X.isFansDays?((t||e).innerHTML="作者已设置关注7天后才可留言",dt(e,"block")):X.onlyFansCanComment&&0===X.isFans?((t||e).innerHTML="作者已设置关注后才可以留言",
dt(e,"block")):x&&(tt?(dt(U.commentPC),dt(U.inputPC)):dt(U.addBtn,"flex"));
},bt=function(e){
var n=Date.now(),o=e.resp,i=e.loadTime,m=e.forceRefresh,s=e.notFirstRender;
if(X.onlyFansCanComment=o.only_fans_can_comment,X.isFans=o.is_fans,window.isPaySubscribe&&!window.isPaid&&(X.canC2CReply=!1),
X.replyFlag=X.canC2CReply?o.reply_flag:0,_t(X.reportData.handleList,encodeURIComponent(JSON.stringify({
comment_id:X.commentId,
offset:X.offset,
url:$
}))),1!==o.enabled?(mt&&(mt.style.display="none"),o.elected_comment=[],o.elected_comment_total_cnt=0):mt&&(mt.style.display="block"),
0===X.offset){
X.headImg=o.logo_url,X.nickName=o.nick_name,m&&(X.contentIDs=[]);
var a=o.elected_comment;
a&&a.length?(dt(U.main),X.cmtList.render(a),!et&&Ct(w.getId("js_cmt_nofans1")),o.elected_comment_total_cnt<=10&&dt(U.statement),
N||"5"!==window.item_show_type||(N=!0,Math.random()<.1&&(t.saveSpeeds({
uin:window.uin,
pid:675,
speeds:[{
sid:27,
time:Date.now()-window.logs.pagetime.page_begin
}]
}),t.send())),Y=!0,It(m,s)):(rt(U.main),!et&&Ct(w.getId("js_cmt_nofans2"),w.getId("js_cmt_nofans2_inner")));
var c=mt.getBoundingClientRect().y;
location.href.indexOf("scrolltodown")>-1&&c&&window.scrollTo(0,c-25);
}else{
var a=o.elected_comment;
a&&a.length&&X.cmtList.add({
data:a
});
}
0===o.elected_comment_total_cnt?(X.offset=-1,rt(U.loading),rt(U.statement)):X.offset+Z>=o.elected_comment_total_cnt?(X.offset=-1,
rt(U.loading),dt(U.statement)):X.offset+=o.elected_comment.length,window.ipados13_font_scale&&f.setFontSize(U.main,window.ipados13_font_scale/100),
yt(),w.setTwoTabHeight("js_comment_content"),i&&pt(i,Date.now()-n);
},jt=function(e){
if(X.commentId=window.comment_id,0!==Number(X.commentId)){
var t=e.notFirstRender,n=e.forceRefresh,o=e.cb;
n=n===!0,n&&(X.offset=0);
var m=s.getScrollTop(),d=document.documentElement.scrollHeight;
if(!(W||-1===X.offset||X.offset>0&&d-m-F>500)){
if("number"==typeof X.commentCount&&0===X.commentCount&&!n)return void bt({
resp:{
enabled:1,
elected_comment:[],
elected_comment_total_cnt:0,
my_comment:[],
only_fans_can_comment:X.onlyFansCanComment,
is_fans:X.isFans,
logo_url:X.headImg,
nick_name:X.nickName
}
});
var r=i.join("/mp/appmsg_comment",{
action:"getcomment",
scene:X.reportData.scene,
appmsgid:window.appmsgid,
idx:window.idx,
comment_id:X.commentId,
offset:X.offset,
limit:Z,
send_time:window.send_time
},!0),p=+new Date;
W=!0,dt(U.loading),gt();
try{
X.scrollCount++,n&&(H=[]),X.scrollCount>1&&!n&&_t(X.reportData.moreList,encodeURIComponent(r)),
H.indexOf(r)>-1&&_t(X.reportData.repeatList,encodeURIComponent(r)),H.push(r);
}catch(_){
console.error(_);
}
st&&console.info("[图文评论] 开始请求评论数据:",r),l("[Appmsg comment] start get comment data, url:"+r),
c({
url:r,
dataType:"json",
success:function(e){
var i=e.base_resp&&e.base_resp.ret;
0===i?o&&o({
resp:e,
forceRefresh:n,
notFirstRender:t,
loadTime:Date.now()-p
}):_t(X.reportData.errList,"type:resperr;url:"+encodeURIComponent(r)+";ret="+i),
l("[Appmsg comment] get comment success");
},
error:function(){
_t(X.reportData.errList,"type:ajaxerr;url:"+encodeURIComponent(r)),l("[Appmsg comment] get comment ajax error");
},
complete:function(){
W=!1,rt(U.loading),a.off(window,"scroll",gt);
}
});
}
}
},ht=function(e){
var t=j.validContent(e);
return t.valid&&tt&&(t.content=q.value),t;
},vt=!1,kt=function(e){
var t=e.content,n=e.successBegin,o=e.successEnd,m=e.fail,s=e.complete;
vt||!function(){
vt=!0,B!==t&&(G=Date.now());
var e=i.join("/mp/appmsg_comment",{
action:"addcomment",
scene:X.reportData.scene,
appmsgid:window.appmsgid,
idx:window.idx,
comment_id:X.commentId,
sn:window.sn
},!0);
c({
url:e,
data:{
content:t,
title:at,
head_img:X.headImg,
nickname:X.nickName,
client_id:G
},
type:"POST",
dataType:"json",
success:function(i){
switch("function"==typeof n&&n(),+i.ret){
case 0:
window.weui.toast("已留言",750);
var s={
content:t,
nick_name:X.nickName,
create_time:Date.now()/1e3|0,
is_elected:0,
logo_url:X.headImg,
like_status:0,
like_num_format:0,
like_num:0,
is_from_friend:0,
is_from_me:1,
my_id:i.my_id,
content_id:i.content_id,
reply_new:{
reply_list:[]
}
};
return dt(U.mylistContainer),dt(U.mylistFooter),X.myList.add({
data:[s],
mode:"unshift"
}),ft(),void("function"==typeof o&&o());

case-6:
window.weui.alert("你留言的太频繁了，休息一下吧");
break;

case-7:
window.weui.alert("你还未关注该公众号，不能参与留言");
break;

case-10:
window.weui.alert("字数不能多于"+T+"个");
break;

case-15:
window.weui.alert("留言已关闭");
break;

case-18:
window.weui.alert("你在此文章的留言次数已达上限");
break;

default:
B=t,window.weui.alert("系统错误，请重试");
}
_t(X.reportData.addCommentErr,"type:resperr;url:"+encodeURIComponent(e)+";ret="+i.ret),
"function"==typeof m&&m();
},
error:function(t){
console.log(t),_t(X.reportData.addCommentErr,"type:ajaxerr;url:"+encodeURIComponent(e)),
"function"==typeof m&&m();
},
complete:function(){
vt=!1,"function"==typeof s&&s();
}
});
}();
},Lt=function(){
var e=q.getSubmit(),t=q.getInput();
if(e.disabled!==!0){
var n=ht(tt?q.value:t.value),o=n.valid,i=n.content;
o&&(e.disabled=!0,kt({
content:i,
successBegin:function(){
!tt&&q.hideEmotionPannel();
},
successEnd:function(){
tt?(q.hide(),dt(U.inputPC)):t.value="";
},
complete:function(){
""!==t.value&&(e.disabled=!1);
}
}));
}
},Dt=function(){
var e=i.join("/mp/appmsg_comment",{
action:"getmycomment",
scene:X.reportData.scene,
appmsgid:window.appmsgid,
idx:window.idx,
comment_id:X.commentId
},!0);
0===K&&(K=1,Array.prototype.forEach.call(U.myCmtLoading,dt),c({
url:e,
dataType:"json",
success:function(t){
var n=t.base_resp&&t.base_resp.ret;
if(0===n){
K=2;
var o=t.my_comment;
o&&o.length&&(dt(U.mylistContainer),dt(U.mylistFooter),X.myList.render(o),X.myList.getIsOversize()&&dt(U.mylistFolder)),
J=!0,It(!0,!1);
}else K=0,_t(X.reportData.errComment,"type:resperr;url:"+encodeURIComponent(e)+";ret="+n);
},
error:function(){
K=0,_t(X.reportData.errComment,"type:ajaxerr;url:"+encodeURIComponent(e));
},
complete:function(){
Array.prototype.forEach.call(U.myCmtLoading,rt);
}
}));
},Rt=function(){
var e="discuss_form_editing";
return{
enterEditing:function(){
Q=!0,C.canUseCancel&&(U.addBtn.classList.add(e),U.cmtWritePlaceholder.innerHTML="正在输入...");
},
leaveEditing:function(){
Q&&(Q=!1,C.canUseCancel&&(U.addBtn.classList.remove(e),U.cmtWritePlaceholder.innerHTML="写下你的留言",
y.isAndroid&&(document.body.style.marginBottom="0px")));
}
};
}(),xt=Rt.leaveEditing,Ft=function(){
switch(ct){
case 2:
X.cmtWriteDialog.show();
break;

case 1:
m.invoke("handleMPPageAction",{
action:"writeComment",
title:at,
comment_id:X.commentId,
style:"white"
});
}
return ct;
},Tt=function(e){
A=!0,O=s.getScrollTop(),!tt&&rt(U.article),X.myList.changeContainer(U.mylistOld),
ft(),dt(U.mine),document.body.classList[X.myList.count?"remove":"add"](ot),window.__second_open__&&o.os.ios&&dt(U.fakebar),
window.scrollTo(0,0),Dt(),!e&&setTimeout(function(){
return q.focus();
},3);
},St=function(){
A=!1,X.myList.changeContainer(U.mylist),rt(U.mine),dt(U.article),window.scrollTo(0,O),
q.blur(),document.body.classList.remove(nt),document.body.classList.remove(ot);
},Pt=function(t,n){
if(1*window.item_show_type===5){
var i=e("pages_new/common_share/video/store.js");
i.dispatch("mp-video-player/auto-next-plugin/cancelAutoNextWhenTipsShowed",6);
}
switch(t&&t.preventDefault(),Ft()){
case 2:
g.report(19048,_extends({
EventType:1,
IsFans:X.isFans,
CommentPageType:3
},z));
break;

case 1:
g.report(19048,_extends({
EventType:1,
IsFans:X.isFans,
CommentPageType:2
},z));
break;

case 0:
default:
if(s.isNativePage()||document.body.classList.add(nt),n)return st&&console.log("FakeHash on comment"),
void Tt();
t.preventDefault(),window.__second_open__&&o.os.ios?Tt():(st&&console.log("push comment"),
r.push("comment")),g.report(19048,_extends({
EventType:1,
IsFans:X.isFans,
CommentPageType:1
},z));
}
},zt=function(){
a.tap(U.mylistFolder,ft),a.on(window,"scroll",gt),a.on(window,"scroll",ut),a.bindVisibilityChangeEvt(function(e){
e&&!lt(U.cmtContainer)&&jt({
notFirstRender:!0,
forceRefresh:!0,
cb:bt
});
});
var e=function t(){
U.mylistFolder?lt(U.mylistFolder)&&(g.report(19462,_extends({
CommentId:parseInt(X.commentId,10)||0,
actiontype:1,
wording:"展开全部留言",
number:X.myList.count,
devicetype:1
},E)),a.off(window,"scroll",t)):a.off(window,"scroll",t);
};
if(a.on(window,"scroll",e),e(),s.bindDebounceScrollEvent(wt),tt)a.tap(U.inputPC,function(){
rt(U.inputPC),q.show(U.inputPC);
});else switch(a.tap(U.cmtWrite,Pt),ct){
case 2:
y.isAndroid&&C.canUseCancel&&C.onGetKeyboardHeight(function(e){
if(Q){
var t=e+55,n=F-U.cmtWrite.getBoundingClientRect().top-t,o={
y:s.getScrollTop()-n
};
Math.abs(n)<150?o.speed=300:o.duration=.3,document.body.style.marginBottom=t+"px",
L(o);
}
});
break;

case 1:
s.listenMpPageAction(function(e){
"deleteComment"===e.action&&X.cmtList.remove({
myId:e.personal_comment_id
}),"deleteCommentReply"===e.action&&X.cmtList.remove({
type:"reply",
myId:e.personal_comment_id,
replyId:e.replyId
}),"praiseComment"===e.action&&(e.reply_id&&0!==e.reply_id?(X.cmtList.setLikeInfo({
type:"reply",
myId:e.personal_comment_id,
replyId:e.reply_id,
likeStatus:e.is_like
}),X.cmtDialog.setReplyLikeInfo({
myId:e.personal_comment_id,
replyId:e.reply_id,
likeStatus:e.is_like
})):X.cmtList.setLikeInfo({
myId:e.personal_comment_id,
likeStatus:e.is_like
}));
});
break;

case 0:
U.goback&&a.on(U.goback,"click",function(e){
e.preventDefault(),St(),rt(U.fakebar);
}),o.os.ios&&window.__second_open__&&!function(){
var e=null,t=null;
a.on(window,"orientationchange",function(){
"none"!==U.fakebar.style.display&&(clearTimeout(e),e=setTimeout(function(){
window.innerWidth!==parseFloat(getComputedStyle(U.fakebar).width)&&(clearTimeout(t),
U.mine.style.height=F+"px",window.scrollBy&&window.scrollBy(0,1),t=setTimeout(function(){
window.scrollBy&&window.scrollBy(0,-1),U.mine.style.height="";
},100));
},50));
});
}();
}
},Et=function(e){
if(X.canC2CReply=0!==(256&e.test_flag),X.onlyFansCanComment=e.only_fans_can_comment,
X.nickName=e.nick_name,X.isFans=e.is_fans,X.headImg=e.logo_url,X.commentCount=e.comment_count,
X.onlyFansDaysCanComment=e.only_fans_days_can_comment,X.isFansDays=e.is_fans_days,
window._has_comment=!0,console.log("inwechat",it,"commentid",X.commentId),!it||0===Number(X.commentId))return void(window._has_comment=!1);
var t=w.getId("js_cmt_container");
mt&&(t.insertAdjacentHTML("afterbegin",d.tmpl(_,{
deviceIsPc:tt
})),X.cmtWriteDialog=new b({
canC2CReply:X.canC2CReply,
onSubmit:function(e){
var t=ht(e),n=t.valid,o=t.content;
n&&(X.cmtWriteDialog.disableSubmit(),kt({
content:o,
successEnd:function(){
X.cmtWriteDialog.hide(),X.cmtWriteDialog.setInputValue("");
},
fail:function(){
X.cmtWriteDialog.enableSubmit();
}
}));
}
}),mt.innerHTML=d.tmpl(p,{
isWxWork:et
})),tt?document.body.classList.add("pages_skin_pc"):0===ct&&document.body.insertAdjacentHTML("beforeend",d.tmpl(u,{
textPageTitle:1*window.item_show_type===10?w.getId("js_text_content").innerHTML.replace(/<(\/?)(?=((a(\s|>))|(\/a))).*?>/g,""):window.msg_title.html(1)
},!1));
var n=w.getId("js_cmt_write");
U={
article:w.getId("js_article"),
mine:w.getId("js_cmt_mine"),
main:w.getId("js_cmt_main"),
input:w.getId("js_cmt_input"),
goback:w.getId("js_cmt_goback"),
list:w.getId("js_cmt_list"),
mylistContainer:w.getId("js_my_list_container"),
mylist:w.getId("js_my_list"),
mylistFolder:w.getId("js_my_list_folder"),
mylistFooter:w.getId("js_my_list_footer"),
mylistOld:w.getId("js_my_list_old"),
morelist:w.getId("js_cmt_morelist"),
loading:w.getId("js_cmt_loading"),
fakebar:w.getId("js_fake_bar"),
statement:w.getId("js_cmt_statement"),
myCmtLoading:w.qsAll(".js_mycmt_loading"),
cmtWrite:n,
cmtWritePlaceholder:w.qs(".js_cmt_write_placeholder",n),
cmtContainer:t,
commentPC:w.getId("js_comment_pc"),
inputPC:w.getId("js_cmt_input_pc"),
containerPC:w.getId("js_cmt_container_pc"),
addbtnPC:w.getId("js_cmt_addbtn_pc"),
emotionSwitchPC:w.getId("js_emotion_wrp_pc"),
inputHolder:w.getId("js_cmt_input_holder"),
addBtn:w.getId("js_cmt_addbtn"),
updateDialog:w.getId("js_update_dialog"),
updateCancel:w.getId("js_update_cancel"),
updateConfirm:w.getId("js_update_confirm"),
deleteReplyPanel:w.getId("js_delete_reply_panel"),
deleteReplyConfirm:w.getId("js_delete_reply_confirm"),
deleteReplyCancel:w.getId("js_delete_reply_cancel"),
cmtDialog:w.getId("js_cmt_dialog")
},X.cmtDialog=new h({
globalData:X,
canAddComment:x,
onGetReplyList:function(e,t){
t.filter(function(e){
return 2===e.is_from;
}).forEach(function(t){
X.cmtList.setLikeInfo({
type:"reply",
contentId:e,
replyId:t.reply_id,
likeStatus:t.reply_like_status,
likeNum:t.reply_like_num
});
});
}
}),X.cmtList=new j({
globalData:X,
container:U.list,
type:"elected",
canAddComment:x,
onPraise:function(e,t,n,o,i){
!X.canC2CReply&&X.myList.setLikeInfo({
type:e,
contentId:t,
replyId:n,
likeStatus:o,
likeNum:i
}),X.cmtDialog.setReplyLikeInfo({
contentId:t,
replyId:n,
likeStatus:o,
likeNum:i
});
},
onRender:function(){
wt();
},
onAdd:function(e,t,n,o,i){
!X.canC2CReply&&X.myList.add({
data:e,
mode:t,
type:n,
contentId:o,
pos:i
}),wt();
},
onRemove:function(e,t,n){
!X.canC2CReply&&X.myList.remove({
type:e,
contentId:t,
replyId:n.reply_id
}),wt();
},
onEmpty:function(e){
"comment"===e&&(rt(U.main),rt(U.statement));
},
beforeShowKeyboard:function(){
xt();
}
}),X.myList=new j({
globalData:X,
container:U.mylist,
type:"mine",
canAddComment:x,
onPraise:function(e,t,n,o,i){
!X.canC2CReply&&X.cmtList.setLikeInfo({
type:e,
contentId:t,
replyId:n,
likeStatus:o,
likeNum:i
});
},
onRender:function(){
wt();
},
onAdd:function(e,t,n,o,i){
!X.canC2CReply&&"reply"===n&&X.cmtList.add({
data:e,
mode:t,
type:n,
contentId:o,
pos:i
}),wt(),ft();
},
onRemove:function(e,t,n){
U.mylistFolder&&X.myList.showTopItems()&&ft(),!X.canC2CReply&&X.cmtList.remove({
type:e,
contentId:t,
replyId:n.reply_id
}),wt();
},
onEmpty:function(){
rt(U.mylistContainer),rt(U.mylistFooter),A&&document.body.classList.add(ot);
},
beforeShowKeyboard:function(){
xt();
}
}),window.cl=X.cmtList,window.ml=X.myList,0===ct&&window.__second_open__&&o.os.ios&&(U.mine.style.marginBottom=getComputedStyle(U.fakebar).height),
!e.notAutoGetComment&&jt({
forceRefresh:!0,
cb:bt
}),"1"===i.getQuery("js_my_comment")&&(1===ct?Ft():0!==ct||tt||Tt(!0)),Dt(),zt(),
tt?q=new v({
placeholder:"留言被公众号精选后，将对所有人可见",
submitText:"留言",
length:T,
onSubmit:Lt,
onHide:function(){
dt(U.inputPC);
}
}):0===ct&&(q=new v({
placeholder:"留言被公众号精选后，将对所有人可见",
submitText:"留言",
length:T,
onSubmit:Lt,
onClick:function(){
window.__second_open__&&rt(U.fakebar);
},
onBlur:function(){
"none"!==U.mine.style.display&&dt(U.fakebar);
}
}),q.show(w.getId("js_comment_input_old"),{
renderType:"append"
}));
},At=function(){
tt||0!==ct||(r.on("comment",function(){
Pt(null,!0);
}),r.on("article",function(){
st&&console.log("FakeHash on article"),St();
}),r.on(function(e){
"comment"===e&&St();
}));
};
return At(),{
initComment:Et,
getCommentData:jt,
renderComment:bt
};
});define("appmsg/like_and_share.js",["biz_common/dom/event.js","biz_common/dom/class.js","biz_wap/jsapi/core.js","pages/utils.js","appmsg/retry_ajax.js","appmsg/set_font_size.js","common/comm_report.js","appmsg/related_article.js","common/utils.js","biz_wap/utils/device.js","biz_wap/utils/mmversion.js","appmsg/appmsg_report.js"],function(e,i,o,n){
"use strict";
var t=e("biz_common/dom/event.js"),s=e("biz_common/dom/class.js"),r=e("biz_wap/jsapi/core.js"),m=e("pages/utils.js"),a=m.formatReadNum,l=e("appmsg/retry_ajax.js"),d=e("appmsg/set_font_size.js"),p=e("common/comm_report.js"),w=e("appmsg/related_article.js"),c=e("common/utils.js"),_=e("biz_wap/utils/device.js"),u=e("biz_wap/utils/mmversion.js"),k=e("appmsg/appmsg_report.js"),g=function(e){
return document.getElementById(e);
},h=function(e){
e.style.display="block";
},j={
likeNum:0,
isLike:0,
likeDom:g("like_old"),
likeNumDom:g("likeNum_old"),
shareDom:g("js_bottom_share"),
collectDom:g("js_bottom_collect"),
oprRightDom:g("js_bottom_opr_right"),
shareBottomBtn:g("js_bottom_share_btn"),
likeBottomBtn:g("js_bottom_zan_btn"),
similarZanCard:g("js_similar_video_card"),
overflowFontScale:1
},f=function(){
var e=0;
try{
e=1*window.atob(window.biz);
}catch(i){}
var o={
BizUin:e,
BizUinStr:window.biz||"",
AppMsgId:window.parseInt(window.mid,10)||0,
ItemIdx:window.parseInt(window.idx,10)||0,
ItemShowType:window.parseInt(window.item_show_type,10)||0,
SessionIdStr:window.sessionid||"",
EnterId:window.parseInt(window.enterid,10)||0,
Scene:window.parseInt(window.source,10)||0,
SubScene:window.parseInt(window.subscene,10)||0,
EventType:4
};
p.report(19048,o);
},v=function(){
setTimeout(function(){
s.removeClass(j.oprRightDom,"sns_opr_overflow");
var e=j.oprRightDom.querySelectorAll(".js_media_tool_meta"),i=g("js_toobar3").getBoundingClientRect().width,o=0;
if(e&&e.length){
g("js_like_wording").textContent="在看",g("js_parise_wording").textContent="赞";
for(var n=0;n<e.length;n++)o+=e[n].getBoundingClientRect().width;
if(console.log("benchmarkWidth",i,o),e.length>1&&(i-o)/(e.length-1)<20){
g("js_like_wording").textContent="",g("js_parise_wording").textContent="";
for(var t=0,n=0;n<e.length;n++)t+=e[n].getBoundingClientRect().width;
(i-t)/(e.length-1)<20&&s.addClass(j.oprRightDom,"sns_opr_overflow");
}
}
},50);
},D=function(){
s.addClass(j.likeDom,"praised"),j.likeNum++;
var e=j.likeNumDom.innerHTML;
("10万+"!==e||"100k+"!==e)&&(j.likeNumDom.innerHTML=a(j.likeNum)),j.likeNumDom.style.display="",
w&&w.render&&w.render("praise");
},b=function(){
s.removeClass(j.likeDom,"praised"),j.likeNum--;
var e=j.likeNumDom.innerHTML;
j.likeNum>=0&&"10万+"!==e&&"100k+"!==e&&(j.likeNumDom.innerHTML=a(j.likeNum)),0===j.likeNum&&(j.likeNumDom.style.display="none");
},y=[],B=function(e){
"function"==typeof e&&y.push(e);
},N=function(e){
j.isLike=j.isLike?0:1,j.isLike?D():b(),l({
url:"/mp/appmsg_like?__biz="+window.biz+"&mid="+window.mid+"&idx="+window.idx+"&like="+j.isLike+"&f=json&appmsgid="+window.appmsgid+"&itemidx="+window.itemidx,
data:{
scene:window.source,
appmsg_like_type:1,
item_show_type:parseInt(window.item_show_type,10),
client_version:window.clientversion,
is_temp_url:window.is_temp_url||0,
style:e||0,
exptype:window.exptype||"",
expsessionid:window.expsessionid||""
},
type:"POST"
}),y.forEach(function(e){
e(j.isLike,j.likeNum);
});
},z=function(e){
return j.likeBottomBtn&&j.likeBottomBtn.disabled===!0?void 0:window.is_temp_url?void("5"!==window.item_show_type||!c.isNativePage()||_.os.pc?window.weui.alert("预览状态下无法操作"):n("预览状态下无法操作")):void N(e);
};
t.on(j.likeDom,"click",function(){
return z();
}),t.on(j.shareDom,"click",function(){
j.shareBottomBtn&&j.shareBottomBtn.disabled===!0||(f(),r.invoke("handleMPPageAction",{
action:"share"
}));
}),t.on(j.collectDom,"click",function(){
r.invoke("handleMPPageAction",{
action:"doFavorite"
}),w&&w.render&&w.render("favorite"),k.shareReport({
link:window.msg_link||window.cgiData&&window.cgiData.msg_link,
action_type:24,
share_source:2
});
});
var I=function(){
v(),d.onFontScaleChange(v),window.addEventListener("resize",v);
},L=function(e){
var i=e.shareShow,o=e.likeShow,n=e.likeNum,t=e.isLike,r=e.shareGray,m=e.likeGray;
j.likeNum=n,j.isLike=t,i&&j.shareDom&&(_.os.pc?_.os.windows&&u.getInner()>="63010000"&&h(j.shareDom):h(j.shareDom)),
r&&j.shareBottomBtn&&(j.shareBottomBtn.disabled=!0),o&&j.likeDom&&h(j.likeDom),m&&j.likeBottomBtn&&(j.likeBottomBtn.disabled=!0),
o&&j.likeNumDom&&0!==n&&(j.likeNumDom.innerHTML=a(j.likeNum),j.likeNumDom.style.display="",
t&&s.addClass(j.likeDom,"praised")),(u.isWechat&&(_.os.iphone&&u.getInner()>"17001000"||_.os.android&&u.getInner()>"27001300")||_.os.windows&&u.getInner()>="63010000")&&h(j.collectDom),
I(),y.forEach(function(e){
e(j.isLike,j.likeNum);
});
};
return{
initLikeShareDom:L,
triggerLike:z,
onLikeChange:B
};
});define("appmsg/like.js",["biz_common/dom/event.js","biz_common/dom/class.js","biz_wap/utils/ajax.js","biz_common/base64.js","biz_wap/utils/jsmonitor_report.js","appmsg/log.js","complain/tips.js","appmsg/retry_ajax.js","biz_wap/jsapi/core.js","biz_wap/utils/mmversion.js","common/utils.js","appmsg/loading.js","biz_wap/utils/device.js","appmsg/pay_report_utils.js","pages/utils.js","appmsg/related_article.js"],function(require,exports,module,alert){
"use strict";
function qs(e){
return document.getElementById(e);
}
function showAppToast(e,i){
JSAPI.invoke("handleMPPageAction",{
action:"showToast",
wording:e||"",
status:i||"success"
});
}
function initLikeEvent(opt){
function show(e){
e.style.display="";
}
function hide(e){
e.style.display="none";
}
function vShow(e){
e.style.visibility="visible";
}
function vHide(e){
e.style.visibility="hidden";
}
function clear(e){
e.value="";
}
function showLoading(){
commonUtils.isNativePage()?showAppToast("发送中","loading"):Loading.show("发送中");
}
function hideLoading(){
commonUtils.isNativePage()?showAppToast("","dismissloading"):Loading.hide();
}
function showToast(e){
commonUtils.isNativePage()?showAppToast(e):(el_toastMsg.innerHTML=e,show(el_likeToast),
setTimeout(function(){
hide(el_likeToast);
},1e3));
}
function alert2(e){
"5"!==window.item_show_type||!commonUtils.isNativePage()||Device.os.pc?window.weui.alert(e):alert(e);
}
function failAlert(e){
return e&&e.length>maxLikeCommentWord?void alert2("想法不可以超过%s字".replace("%s",maxLikeCommentWord)):void alert2("网络异常，请稍后重试");
}
function isAppCommentAvailable(){
return mmversion.isWechat?Device.os.ipad?!1:mmversion.isInMiniProgram?!1:mmversion.isIOS&&mmversion.gtVersion("7.0.8")?!0:mmversion.isAndroid&&mmversion.gtVersion("7.0.8")?!0:commonUtils.isNativePage()&&(mmversion.isIOS||mmversion.isAndroid)?!0:!1:!1;
}
var scrollTop,el_like=opt.likeAreaDom,el_likeNum=opt.likeNumDom,showType=opt.showType,prompted=opt.prompted,haokanLock=!1,startY,jumpWowLock=!1,el_likeToast=qs("js_like_toast"),el_likeBtn=qs("js_like_btn"),el_toastMsg=qs("js_toast_msg"),el_likeEducate=qs("js_like_educate"),el_friend_like=qs("js_friend_like_area"),el_go_wow=qs("js_go_wow"),el_likeComment=qs("js_like_comment"),el_bcommentPanel2=qs("js_comment_panel"),el_likeCommentShare=qs("js_like_comment_share"),el_likeCommentText=qs("js_comment_text"),el_commentCancel=qs("js_comment_cancel"),el_commentConfirm=qs("js_comment_confirm"),el_commentErrorMsg=qs("js_like_comment_msg"),el_commentCurrentCount=qs("js_like_current_cnt"),el_commentArea=qs("js_comment_area"),el_panelLikeTitle=qs("js_panel_like_title"),el_wowClosePanel=qs("wow_close_inform"),el_wowCloseAck=qs("wow_close_ack"),el_alertPanel=qs("js_alert_panel"),el_alertContent=qs("js_alert_content"),el_alertConfirm=qs("js_alert_confirm");
if(el_like&&el_likeNum){
window.appmsg_like_type&&2===window.appmsg_like_type?jsmonitorReport.setSum(114217,0,1):window.appmsg_like_type&&1===window.appmsg_like_type&&jsmonitorReport.setSum(114217,1,1);
var like_report=function(){
var e=el_like.getAttribute("like"),i=el_likeNum.innerHTML,t=parseInt(e)?parseInt(e):0,o=t?0:1,n=parseInt(i)?parseInt(i):0,s=opt.appmsgid||opt.mid,l=opt.itemidx||opt.idx;
if(t){
if(1!==appmsg_like_type)return void sendRecommendAjax(0);
Class.removeClass(el_like,opt.className),el_like.setAttribute("like",0),n>0&&"100000+"!==i&&(el_likeNum.innerHTML=n-1==0?"赞":n-1);
}else if(1===appmsg_like_type)el_like.setAttribute("like",1),Class.addClass(el_like,opt.className),
"100000+"!==i&&(el_likeNum.innerHTML=n+1);else if(2===appmsg_like_type)return void initRecommendPanel();
RetryAjax({
url:"/mp/appmsg_like?__biz="+opt.biz+"&mid="+opt.mid+"&idx="+opt.idx+"&like="+o+"&f=json&appmsgid="+s+"&itemidx="+l,
data:{
is_temp_url:opt.is_temp_url||0,
scene:window.source,
subscene:window.subscene,
appmsg_like_type:window.appmsg_like_type,
item_show_type:parseInt(window.item_show_type,10),
client_version:window.clientversion,
action_type:o?1:2,
device_type:window.devicetype,
exptype:window.exptype||"",
expsessionid:window.expsessionid||""
},
type:"POST"
});
},initRecommendPanel=function(){
sendRecommendAjax(1,"",1);
},isBeenUnvisible=function(e){
function i(){
return window.pageYOffset||document.documentElement.scrollTop||document.body.scrollTop||0;
}
return e.offsetTop+el_likeComment.offsetHeight-i()>=commonUtils.getInnerHeight()?!0:!1;
},disableMove=function(){
document.addEventListener("touchmove",preventMove,{
passive:!1
}),el_likeCommentText.addEventListener("touchstart",getTouchStart,{
passive:!1
}),el_likeCommentText.addEventListener("touchmove",preventText,!1);
},enableMove=function(){
document.removeEventListener("touchmove",preventMove,{
passive:!1
}),el_likeCommentText.removeEventListener("touchstart",getTouchStart,{
passive:!1
}),el_likeCommentText.removeEventListener("touchmove",preventText,!1);
},preventMove=function(e){
var i=e.target;
"TEXTAREA"!==i.tagName&&"BUTTON"!==i.tagName&&(e.preventDefault(),e.stopPropagation());
},getTouchStart=function(e){
var i=e.targetTouches||[];
if(i.length>0){
var t=i[0]||{};
startY=t.clientY;
}
},preventText=function(e){
var i=!1,t=e.changedTouches,o=this.scrollTop,n=this.offsetHeight,s=this.scrollHeight;
if(t.length>0){
var l=t[0]||{},a=l.clientY;
i=a>startY&&0>=o?!1:startY>a&&o+n>=s?!1:!0,i||e.preventDefault();
}
},isShow=function(e){
return"none"===e.style.display||"hidden"===e.style.visibility?!1:""===e.style.display||"block"===e.style.display||"visible"===e.style.visibility?!0:void 0;
},validataComment=function(e,i){
var t=e.value.replace(/^\s+|\s+$/g,"");
sendRecommendAjax(1,t,i);
},showEducatePanel=function(e,i,t){
show(el_likeComment);
var o=window.source||window.cgiData&&window.cgiData.source||0;
return o&&(o=parseInt(o,10),94===o)?void(e&&5===e&&hide(el_likeComment)):void(i||(show(el_likeEducate),
t&&t>0&&(el_friend_like.innerHTML="%s位朋友也在看,".replace("%s",t),document.getElementById("js_friend_like_word").innerText="前往“发现”-“看一看”浏览",
show(el_friend_like)),1===showType&&(hide(el_go_wow),hide(el_likeCommentShare)),
isBeenUnvisible(el_likeComment)&&scrollToShow(el_likeComment),educateExpose()));
},setBtnLike=function(){
el_like.setAttribute("like",1),Class.addClass(el_likeBtn,opt.className),realLikeNum+=1;
var e=el_likeNum.innerHTML;
"10万+"!==e&&(el_likeNum.innerHTML=formatReadNum(realLikeNum));
},setLike2Status=function(e,i,t){
var o="在看";
switch(showType){
case 1:
switch(prompted){
case 0:
showEducatePanel(e,i,t),show(el_likeComment),prompted=1;
break;

case 1:
hide(el_likeEducate),showToast(o);
}
setBtnLike();
break;

case 2:
switch(hide(el_bcommentPanel2),clear(el_likeCommentText),prompted){
case 0:
showEducatePanel(e,i,t),5===e&&hide(el_likeCommentShare);
break;

case 1:
(4===e||5===e)&&showToast(4===e?"已发送":o);
}
5!==e&&(4===e&&"none"!==el_likeEducate.style.display?hide(el_likeCommentShare):4===e?hide(el_likeComment):(show(el_commentArea),
show(el_likeCommentShare),1===prompted&&hide(el_likeEducate),show(el_likeComment),
isBeenUnvisible(el_likeComment)&&scrollToShow(el_likeComment))),4!==e&&setBtnLike(),
prompted=1;
}
enableMove(),commonUtils.isNativePage()&&JSAPI.invoke("handleHaokanAction",{
action:"closeComment"
}),log("[Appmsg] zaikan set like success");
},unsetLike2Status=function(e){
1===e?setTimeout(function(){
alert2(" 已取消，想法已同步删除");
},20):showToast("已取消"),2===showType&&isShow(el_likeComment)&&hide(el_likeComment);
var i=el_likeNum.innerHTML;
Class.removeClass(el_likeBtn,opt.className),el_like.setAttribute("like",0),el_likeComment&&hide(el_likeComment),
realLikeNum-=1,realLikeNum>=0&&"10万+"!==i&&(el_likeNum.innerHTML=formatReadNum(realLikeNum)),
log("[Appmsg] zaikan set unlike success");
},sendRecommendAjax=function sendRecommendAjax(like,comment,type,clientType){
if(!haokanLock){
log("[Appmsg] prepare to send appmsg like request"),showLoading();
var appmsgid=opt.appmsgid||opt.mid,itemidx=opt.itemidx||opt.idx;
haokanLock=!0;
var action_type;
like?(window.isPaySubscribe&&payReportUtils.reportPayAppmsg(12),action_type=type):(window.isPaySubscribe&&payReportUtils.reportPayAppmsg(13),
action_type=2),ajax({
url:"/mp/appmsg_like?__biz="+opt.biz+"&mid="+opt.mid+"&idx="+opt.idx+"&like="+like+"&f=json&appmsgid="+appmsgid+"&itemidx="+itemidx,
data:{
is_temp_url:opt.is_temp_url||0,
scene:window.source,
subscene:window.subscene,
appmsg_like_type:window.appmsg_like_type,
item_show_type:parseInt(window.item_show_type,10),
client_version:window.clientversion,
comment:comment?comment:"",
prompted:1,
style:clientType||showType,
action_type:action_type,
passparam:window.passparam,
request_id:(new Date).getTime(),
device_type:window.devicetype,
exptype:window.exptype||"",
expsessionid:window.expsessionid||""
},
type:"POST",
success:function success(res){
haokanLock=!1;
var data=eval("("+res+")");
hideLoading(),log("[Appmsg] success send appmsglike like "+like+" return value is "+JSON.stringify(res)),
0==data.base_resp.ret?(like?(setLike2Status(type,data.is_eu_user,data.friend_like_num),
relatedArticles&&relatedArticles.render&&relatedArticles.render("like")):unsetLike2Status(data.has_comment),
connectWithApp(like,comment,clientType)):failAlert(comment);
},
error:function(){
hideLoading(),failAlert(),haokanLock=!1;
}
});
}
};
JSAPI.on("menu:haokan",function(e){
var i=0===parseInt(e.recommend)?0:1;
if(0===i)sendRecommendAjax(i,"",2,clientShowType);else{
var t="";
t=e.comment;
var o=1===e.scene?4:5;
sendRecommendAjax(i,t,o,clientShowType);
}
});
var connectWithApp=function(e,i){
var t={
origin:"mp",
isLike:e?1:0,
url:encodeURIComponent(msg_link.html(!1)),
content:i?i:""
};
JSAPI.invoke("handleHaokanAction",{
action:actionString,
recommend:e?1:0,
server_data:JSON.stringify(t)
},function(e){
console.log("handleHaokanAction",e);
}),JSAPI.invoke("handleHaokanAction",{
action:actionForClient,
permission:1,
recommend:e?1:0
},function(e){
console.log("handleHaokanAction for client",e);
});
},goWoW=function(){
jumpWowLock||(jumpToWowClickReport(),jumpWowLock=!0,JSAPI.invoke("handleHaokanAction",{
action:"jumpToWow",
extParams:JSON.stringify({
autoDropLoad:!0
})
},function(e){
jumpWowLock=!1,console.log("jumpToWow",e),e.err_msg&&"handleHaokanAction:fail_entrance_not_open"===e.err_msg?show(el_wowClosePanel):"handleHaokanAction:fail  action not support"===e.err_msg||"handleHaokanAction:fail, action not support"===e.err_msg?alert2("微信版本过低，暂不支持该操作"):"handleHaokanAction:ok"===e.err_msg&&hide(el_likeComment),
JSAPI.invoke("handleHaokanAction",{
action:actionString,
server_data:JSON.stringify({
origin:"mp",
autoDropLoad:!0
})
},function(e){
console.log("sendAutoDropLoad",e);
});
}));
},likeClickReport=function(){
ajax({
url:"/mp/appmsgreport?action=appmsglikeclickcomment&__biz="+opt.biz+"&mid="+opt.mid+"&idx="+opt.idx+"&f=json&appmsgid="+appmsgid+"&itemidx="+itemidx,
data:{
is_temp_url:opt.is_temp_url||0,
scene:window.source,
subscene:window.subscene,
appmsg_like_type:window.appmsg_like_type,
item_show_type:parseInt(window.item_show_type,10),
client_version:window.clientversion,
device_type:window.devicetype
},
type:"POST"
});
},likeExpose=function e(){
var i=document.documentElement.scrollTop||window.pageYOffset||document.body.scrollTop,t=qs("like3").offsetTop,o=opt.appmsgid||opt.mid,n=opt.itemidx||opt.idx;
i+commonUtils.getInnerHeight()>t&&t>=i&&(ajax({
url:"/mp/appmsgreport?action=appmsglikeexposure&__biz="+opt.biz+"&mid="+opt.mid+"&idx="+opt.idx+"&f=json&appmsgid="+o+"&itemidx="+n,
data:{
is_temp_url:opt.is_temp_url||0,
scene:window.source,
subscene:window.subscene,
appmsg_like_type:window.appmsg_like_type,
item_show_type:parseInt(window.item_show_type,10),
client_version:window.clientversion,
device_type:window.devicetype
},
type:"POST"
}),DomEvent.off(window,"scroll",e));
},educateExpose=function i(){
var e=(document.documentElement.scrollTop||window.pageYOffset||document.body.scrollTop,
opt.appmsgid||opt.mid),t=opt.itemidx||opt.idx,o=window.item_show_type,n=window.enterid||window.cgiData&&window.cgiData.enterid||"";
el_likeEducate&&"none"!=el_likeEducate.style.display&&commonUtils.getInnerHeight()>el_likeEducate.getBoundingClientRect().top&&el_likeEducate.getBoundingClientRect().top+el_likeEducate.getBoundingClientRect().height>0&&(ajax({
url:"/mp/webcommreport?action=report&report_useruin=1&__biz="+window.biz,
type:"POST",
data:{
logid:18266,
buffer:["",Base64.decode(opt.biz),e,t,window.source,window.subscene,1,o,sessionid,n]
},
async:!1,
timeout:2e3
}),DomEvent.off(window,"scroll",i));
},jumpToWowClickReport=function(){
var e=opt.appmsgid||opt.mid,i=opt.itemidx||opt.idx,t=window.enterid||window.cgiData&&window.cgiData.enterid||"";
ajax({
url:"/mp/webcommreport?action=report&report_useruin=1&__biz="+window.biz,
type:"POST",
data:{
logid:18266,
buffer:["",Base64.decode(opt.biz),e,i,window.source,window.subscene,2,window.item_show_type,sessionid,t]
},
async:!1,
timeout:2e3
});
};
DomEvent.on(el_alertConfirm,"click",function(){
el_alertPanel.style.display="none";
}),DomEvent.on(el_like,"click",function(e){
if(el_likeBtn.disabled!==!0){
if(window.is_temp_url)return void alert2("预览状态下无法操作");
var i=el_like.getBoundingClientRect();
return log("[Appmsg zaikan location] top: "+i.top+" left: "+i.left+" bottom: "+i.bottom+" right: "+i.right),
log("[Appmsg zaikan click] clientX: "+e.clientX+" clientY: "+e.clientY),e.currentTarget.classList.contains("js_disabled")?!1:(like_report(e),
!1);
}
}),DomEvent.on(el_wowCloseAck,"click",function(){
hide(el_wowClosePanel);
}),DomEvent.on(qs("js_mask_2"),"mousedown",function(){
hide(el_bcommentPanel2),clear(el_likeCommentText),vHide(el_commentErrorMsg),enableMove();
}),DomEvent.on(el_commentConfirm,"mousedown",function(){
validataComment(el_likeCommentText,4);
}),DomEvent.on(el_commentCancel,"mousedown",function(){
hide(el_bcommentPanel2),clear(el_likeCommentText),vHide(el_commentErrorMsg),enableMove();
}),DomEvent.on(el_likeCommentShare,"click",function(){
return commonUtils.isNativePage()?void JSAPI.invoke("handleHaokanAction",{
action:"writeComment",
style:"white"
}):(scrollTop=document.body.scrollTop||document.documentElement.scrollTop,1*window.item_show_type===10&&(el_panelLikeTitle.innerHTML=window.msg_title.replace(/<(\/?)(?=((a(\s|>))|(\/a))).*?>/g,"")),
show(el_bcommentPanel2),el_likeCommentText.focus(),el_commentConfirm.setAttribute("disabled","disabled"),
disableMove(),void likeClickReport());
}),DomEvent.on(el_likeCommentText,"focus",function(){}),DomEvent.on(el_likeCommentText,"blur",function(){
window.scrollTo(0,scrollTop);
}),DomEvent.on(window,"scroll",likeExpose),DomEvent.on(window,"scroll",educateExpose),
DomEvent.on(el_go_wow,"click",goWoW);
var scrollToShow=function(e){
e.scrollIntoView(!1);
};
DomEvent.on(el_likeCommentText,"input",function(e){
var i=el_likeCommentText.value.replace(/^\s+|\s+$/g,"");
i.length>maxLikeCommentWord?(el_commentCurrentCount.innerHTML=i.length,vShow(el_commentErrorMsg)):vHide(el_commentErrorMsg),
i.length>0&&i.length<=maxLikeCommentWord?el_commentConfirm.removeAttribute("disabled"):el_commentConfirm.setAttribute("disabled","disabled"),
Device.os.ios&&e.data&&doubleInputChar.indexOf(e.data)>-1&&(focusTag=!0);
}),DomEvent.on(el_likeCommentText,"click",function(){
Device.os.ios&&focusTag&&(el_likeCommentText.blur(),el_likeCommentText.focus(),focusTag=!1);
});
}
}
function showLikeNum(e){
var i=e||{};
if(i.show){
var t=i.likeAreaDom,o=i.likeNumDom,n=document.getElementById("js_like_btn");
t&&(t.style.display=i.likeAreaDisplayValue,t.style.visibility="",i.liked&&(1===appmsg_like_type?Class.addClass(t,i.className):Class.addClass(n,i.className)),
t.setAttribute("like",i.liked?"1":"0"),i.likeGray&&(n.disabled=!0));
var s=1===appmsg_like_type?"赞":"";
realLikeNum=i.likeNum||s,1===appmsg_like_type?(parseInt(realLikeNum)>1e5?realLikeNum="100000+":"",
o&&(o.innerHTML=realLikeNum)):2===appmsg_like_type&&(o.innerHTML=formatReadNum(realLikeNum));
}
}
var DomEvent=require("biz_common/dom/event.js"),Class=require("biz_common/dom/class.js"),ajax=require("biz_wap/utils/ajax.js"),Base64=require("biz_common/base64.js"),jsmonitorReport=require("biz_wap/utils/jsmonitor_report.js"),log=require("appmsg/log.js"),Tips=require("complain/tips.js"),RetryAjax=require("appmsg/retry_ajax.js"),JSAPI=require("biz_wap/jsapi/core.js"),actionString="submitMsgToTL",actionForClient="update_recommend_status",mmversion=require("biz_wap/utils/mmversion.js"),commonUtils=require("common/utils.js"),Loading=require("appmsg/loading.js"),realLikeNum,clientShowType=5,Device=require("biz_wap/utils/device.js"),payReportUtils=require("appmsg/pay_report_utils.js"),_require=require("pages/utils.js"),formatReadNum=_require.formatReadNum,relatedArticles=require("appmsg/related_article.js"),maxLikeCommentWord=200,focusTag=!1,doubleInputChar=["“”","‘’","（）","《》","〈〉","「」","『』","〔〕","【】","［］","[]","｛｝","{}","()","<>"];
return{
initLikeEvent:initLikeEvent,
showLikeNum:showLikeNum
};
});define("appmsg/read.js",["pages/utils.js","biz_wap/utils/device.js"],function(e){
"use strict";
function i(e){
var i=e||{},n=1586325600,d="undefined"!=typeof window.ct?parseInt(window.ct,10):0;
if(i.show){
var s=i.readAreaDom,o=i.readNumDom;
s&&(s.style.display=i.readAreaDisplayValue);
var r=i.readNum||1,w=window.ori_send_time||window.cgiData&&window.cgiData.ori_send_time||0,p=/(WindowsNT)|(Windows NT)|(Macintosh)/i.test(navigator.userAgent),m=1566025200,u=1565971200,_=a.os.ios||p?m:u;
parseInt(w,10)>_&&window.item_show_type&&"5"===window.item_show_type&&(n>d?("en"!==window.LANG&&(document.getElementById("readTxt").innerText="播放"),
r=i.videouv||0):("en"!==window.LANG&&(document.getElementById("readTxt").innerText="观看"),
r=i.readNum||0)),1===window.appmsg_like_type?(parseInt(r,10)>1e5?r="100000+":"",
o&&(o.innerHTML=r)):2===window.appmsg_like_type&&(o.innerHTML=t(r),""===o.innerHTML&&(o.innerHTML="0"));
}
}
var n=e("pages/utils.js"),t=n.formatReadNum,a=e("biz_wap/utils/device.js");
return{
showReadNum:i
};
});define("appmsg/share_tpl.html.js",[],function(){
return'<div class="rich_media_extra">\n    <a href="<#= url #>" class="share_appmsg_container appmsg_card_context flex_context">\n        <div class="flex_hd">\n            <i class="share_appmsg_icon"> </i>\n        </div>\n        <div class="flex_bd">\n            <div class="share_appmsg_title">分享给订阅用户</div>\n            <p class="share_appmsg_desc">可快速分享原创文章给你的公众号订阅用户</p>\n        </div>\n    </a>\n</div>\n';
});define("appmsg/appmsgext.js",["appmsg/log.js","biz_wap/utils/ajax.js","rt/appmsg/getappmsgext.rt.js","biz_common/utils/wxgspeedsdk.js","biz_common/utils/url/parse.js"],function(e){
"use strict";
function i(e){
var i={
biz:"",
appmsg_type:"",
mid:"",
sn:"",
album_id:"",
idx:"",
scene:"",
title:"",
ct:"",
abtest_cookie:"",
devicetype:"",
version:"",
is_need_ticket:0,
is_need_ad:0,
comment_id:"",
is_need_reward:0,
both_ad:0,
reward_uin_count:0,
send_time:"",
msg_daily_idx:"",
is_original:0,
is_only_read:0,
req_id:"",
pass_ticket:"",
is_temp_url:0,
more_read_type:0,
rtId:"",
rtKey:"",
appmsg_like_type:1,
related_video_sn:"",
vid:"",
is_pay_subscribe:0,
pay_subscribe_uin_count:0,
has_red_packet_cover:0,
related_video_num:e.isPublicRelatedVideo?10:5,
album_video_num:5,
onSuccess:function(){},
onError:function(){}
};
for(var o in e)e.hasOwnProperty(o)&&(i[o]=e[o]);
console.info("[(评论、点赞、赞赏) 发送请求]: ",new Date),t({
url:"/mp/getappmsgext?f=json&mock="+n.getQuery("mock"),
data:{
r:Math.random(),
__biz:i.biz,
appmsg_type:i.appmsg_type,
mid:i.mid,
sn:i.sn,
idx:i.idx,
scene:i.scene,
title:encodeURIComponent(i.title.htmlDecode()),
ct:i.ct,
abtest_cookie:i.abtest_cookie,
devicetype:i.devicetype.htmlDecode(),
version:i.version.htmlDecode(),
is_need_ticket:i.is_need_ticket,
is_need_ad:i.is_need_ad,
comment_id:i.comment_id,
is_need_reward:i.is_need_reward,
both_ad:i.both_ad,
reward_uin_count:i.is_need_reward?i.reward_uin_count:0,
send_time:i.send_time,
msg_daily_idx:i.msg_daily_idx,
is_original:i.is_original,
is_only_read:i.is_only_read,
req_id:i.req_id,
pass_ticket:i.pass_ticket,
is_temp_url:i.is_temp_url,
item_show_type:i.item_show_type,
tmp_version:1,
more_read_type:i.more_read_type,
appmsg_like_type:i.appmsg_like_type,
related_video_sn:i.related_video_sn,
related_video_num:i.related_video_num,
vid:i.vid,
is_pay_subscribe:i.is_pay_subscribe,
pay_subscribe_uin_count:i.pay_subscribe_uin_count,
has_red_packet_cover:i.has_red_packet_cover,
album_id:0x11fd1c7c75070000,
album_video_num:i.album_video_num,
cur_album_id:window.appmsg_album_info?window.appmsg_album_info.id:"",
is_public_related_video:i.isPublicRelatedVideo,
encode_info_by_base64:i.encodeInfoByBase64
},
type:"POST",
dataType:"json",
rtId:i.rtId,
rtKey:i.rtKey,
rtDesc:_,
async:!0,
success:function(e){
if(console.info("[(评论、点赞、赞赏) 响应请求]: ",new Date,e),s("[Appmsg] success get async data"),
"function"==typeof i.onSuccess&&i.onSuccess(e),e)try{
s("[Appmsg] success get async data, async data is: "+JSON.stringify(e));
}catch(t){}else s("[Appmsg] success get async data, async data is empty");
if(!d&&"5"===window.item_show_type){
var _=Date.now()-window.logs.pagetime.page_begin;
if(d=!0,Math.random()>.1)return;
a.saveSpeeds({
uin:window.uin,
pid:675,
speeds:[{
sid:29,
time:_
}]
}),a.send();
}
},
error:function(){
s("[Appmsg] error get async data, biz="+i.biz+", mid="+i.mid),"function"==typeof i.onError&&i.onError();
},
complete:function(){
"function"==typeof i.onComplete&&i.onComplete();
}
});
}
var s=e("appmsg/log.js"),t=e("biz_wap/utils/ajax.js"),_=e("rt/appmsg/getappmsgext.rt.js"),a=e("biz_common/utils/wxgspeedsdk.js"),n=e("biz_common/utils/url/parse.js"),d=void 0;
return{
getData:i
};
});define("appmsg/img_copyright_tpl.html.js",[],function(){
return'<span class="original_img_wrp">            \n    <span class="tips_global">来自: <#=source_nickname#></span>\n</span>    ';
});define("pages/video_ctrl.js",[],function(){
"use strict";
function i(i){
i=i||window;
var n=i.cgiData;
return n&&2==n.ori_status&&1==n.is_mp_video&&(n.nick_name||n.hit_username)?!0:!1;
}
function n(i){
return i=i||window,!1;
}
function t(){
return!1;
}
function e(){
return-1!=w.indexOf("&dd=1")?!1:"54"==r.appmsg_type?!1:!0;
}
function o(){
var i;
if(parent==window)i=window;else try{
{
r.__videoDefaultRatio;
}
i=r;
}catch(n){
i=window;
}
var t=i.__videoDefaultRatio||16/9;
return"54"==i.appmsg_type?t:t;
}
var r=window.withoutIframe?window:window.parent.window,w=window.location.href;
return{
showPauseTips:e,
showVideoLike:t,
showVideoDetail:n,
showReprint:i,
getRatio:o
};
});define("pages/create_txv.js",["biz_wap/utils/jsmonitor_report.js","biz_wap/utils/ajax_load_js.js","pages/loadscript.js"],function(e){
"use strict";
function o(){
"function"!=typeof window.__createTxVideo&&(window.__createTxVideo=function(e){
n(e);
});
}
function n(e){
var o=function(){},n=function(){};
"function"==typeof e.onSuccess&&(n=e.onSuccess),"function"==typeof e.onError&&(o=e.onError),
r.Load({
url:a.jsUrl,
version:a.jsVersion,
useCache:!0,
win:e.win,
onSuccess:function(s){
2!=s.code&&3!=s.code||0!=s.queueIndex||(i.setSum("64728","111",1),i.setSum("64728","112",1));
var u=e.win||window,c=!0;
if(u.Txp&&"function"==typeof u.Txp.Player?(c=!0,0==s.queueIndex&&(2==s.code?i.setSum("64728","116",1):3==s.code&&i.setSum("64728","117",1))):(c=!1,
0==s.queueIndex&&(2==s.code?i.setSum("64728","114",1):3==s.code&&i.setSum("64728","115",1))),
c){
var d=t({
win:u,
options:e
});
n({
player:d
});
}else r.ClearCache({
win:u,
version:a.jsVersion,
url:a.jsUrl
}),o();
},
onError:function(o){
0==o.queueIndex&&(i.setSum("64728","111",1),i.setSum("64728","118",1),51==o.code?i.setSum("64728","119",1):52==o.code?i.setSum("64728","120",1):53==o.code&&i.setSum("64728","121",1)),
s(e);
}
});
}
function t(e){
var o=e.win||window,n=e.options,t=new o.Txp.Player({
containerId:n.containerId,
vid:n.vid,
width:n.width,
height:n.height,
autoplay:n.autoplay===!0?!0:!1,
allowFullScreen:n.allowFullScreen===!0?!0:!1,
chid:17
});
return t;
}
function s(e){
var o=function(){},n=function(){};
"function"==typeof e.onSuccess&&(n=e.onSuccess),"function"==typeof e.onError&&(o=e.onError);
var s=a.jsUrl;
s+=-1==s.indexOf("?")?"?"+a.customerParam+"="+a.jsVersion:"&"+a.customerParam+"="+a.jsVersion,
u({
win:e.win,
url:s,
timeout:1e4,
type:"JS",
callback:function(){
i.setSum("64728","122",1);
var s=e.win||window;
if(s.Txp&&"function"==typeof s.Txp.Player){
i.setSum("64728","124",1);
var r=t({
win:e.win,
options:e
});
n({
player:r
});
}else i.setSum("64728","123",1),o();
},
onerror:function(e){
switch(i.setSum("64728","122",1),1*e){
case 400:
a.jsLoadState=4,i.setSum("64728","125",1);
break;

case 500:
a.jsLoadState=5,i.setSum("64728","126",1);
break;

default:
a.jsLoadState=6,i.setSum("64728","127",1);
}
o();
}
});
}
var i=e("biz_wap/utils/jsmonitor_report.js"),r=e("biz_wap/utils/ajax_load_js.js"),u=e("pages/loadscript.js"),a={
customerParam:"wxv",
jsUrl:"//vm.gtimg.cn/tencentvideo/txp/js/iframe/api.js?",
jsVersion:"v1"
};
return{
createTxVideo:n,
createGlobalFunc:o
};
});define("appmsg/pay_read_utils.js",["biz_wap/ui/weui.js","biz_wap/jsapi/core.js","biz_common/dom/event.js","biz_common/dom/class.js","biz_wap/utils/mmversion.js","biz_wap/utils/device.js","appmsg/pay_report_utils.js","common/utils.js","pages/utils.js"],function(e){
"use strict";
e("biz_wap/ui/weui.js");
var t=e("biz_wap/jsapi/core.js"),i=e("biz_common/dom/event.js"),n=e("biz_common/dom/class.js"),a=e("biz_wap/utils/mmversion.js"),o=e("biz_wap/utils/device.js"),r=e("appmsg/pay_report_utils.js"),s=e("common/utils.js"),d=e("pages/utils.js"),w=function(e){
var t=arguments.length<=1||void 0===arguments[1]?document:arguments[1];
return t.querySelector(e);
},c=window.payFreeGift,l=function(){
for(var e=Object.create(null),t=1;6>t;t++)e[t]=s.once(r.reportSend.bind(null,t));
return function(t){
return e[t]();
};
}(),f=document.documentElement&&document.documentElement.clientWidth||window.innerWidth;
try{
var u=w("#img-content");
if(u){
var p=u.getBoundingClientRect();
p.width&&(f=p.width);
}
}catch(_){
console.error(_);
}
var m=32,g=8,y='<div class="pay__tag-reward js_reward"></div>',h={
dom:{
payFee:[w("#js_pay_panel .js_pay_fee"),w("#js_pay_panel_bottom .js_pay_fee")],
wrap:w("#js_pay_wall_wrap"),
payNum:w("#js_pay_num"),
rewardNumWrap:w("#js_pay_reward_num_wrap"),
rewardNum:w("#js_pay_reward_num"),
wall:w("#js_pay_wall"),
sendTips:w("#js_pay_preview_tips"),
giftBar:w("#js_pay_gift_bar"),
giftBarTitle:w("#js_pay_gift_bar_title"),
sendGift:w("#js_send_pay_gift")
},
perLine:null,
data:{}
},v=function(e){
e&&(/^http/.test(e)||(e=location.protocol+"//"+location.host+e),e.indexOf("#")<0&&(e+="#wechat_redirect"),
-1!==navigator.userAgent.indexOf("MicroMessenger")&&(a.isIOS||a.isAndroid||a.isWp)?t.invoke("openUrlWithExtraWebview",{
url:e,
openType:1
},function(t){
-1===t.err_msg.indexOf("ok")&&(location.href=e);
}):location.href=e);
},b=function(){
var e=h.dom,t=h.data,i=parseInt(t.pay_cnt,10);
e.payNum.innerHTML=i>=1e4||t.is_pay_cnt_cut?"en"===window.LANG?"10k+":"1万+":i+"",
t.rewardTotal?(e.rewardNum.innerHTML=t.rewardTotal+(t.rewardTotalCut?"+":""),e.rewardNumWrap.style.display=""):e.rewardNumWrap.style.display="none";
for(var n=3*h.perLine,a="",o=0,r=t.pay_head_imgs.length;r>o;o++){
var s=t.reward_status_list?t.reward_status_list[o]:0;
if(a+='<div class="pay__avatar-wrp"><img src="'+t.pay_head_imgs[o]+'">'+(s?y:"")+"</div>",
o>=n-1)break;
}
e.wall.innerHTML=a;
},j=function(){
var e=h.dom;
i.tap(e.payNum,function(){
v("/mp/paysub?action=evaluate_show_page&__biz="+window.biz+"&mid="+window.mid+"&idx="+window.idx+"&sn="+window.sn+"&link="+encodeURIComponent(window.msg_link)+"&from_scene="+window.source+"&from_subscene="+window.subscene+"&is_fans="+window.isFans);
}),i.tap(e.rewardNum,function(){
var e=(Math.ceil((s.getInnerHeight()-188)/42)+1)*Math.floor((f-15)/42);
v("/mp/reward?act=getrewardheads&__biz="+window.biz+"&appmsgid="+window.mid+"&idx="+window.idx+"&sn="+window.sn+"&offset=0&count="+e+"&source=1");
}),i.tap(e.sendGift,function(){
if(o.os.iphone||o.os.ipad||o.os.android){
var t=h.data.gift_url.html(),i="",a=t.indexOf("#");
-1!==a&&(i=t.substring(a),t=t.substring(0,a)),l(n.hasClass(e.giftBar,"pay__gift-send_static")?5:3),
v(t+"&sessionid="+window.sessionid+"&enterid="+window.enterid+"&scene="+window.source+"&subscene="+window.subscene+i);
}else window.weui.alert("请使用移动端微信打开");
});
},B=function(e,t,o){
if(window.isPaySubscribe){
var s=h.dom;
if(e=JSON.parse(JSON.stringify(e)),!e.fee||window.isPaid||window.IAPProductInfo||!function(){
var t=Math.floor(e.fee/100);
s.payFee.forEach(function(e){
!window.iapPriceInfo.currency_symbol&&(e.innerHTML="￥"+t+".00"),e.parentNode.dataset.ready=1;
});
}(),a.isIOS&&e.fee&&(window.IAPProductInfo?("CNY"!==window.IAPProductInfo.currencyCode&&r.report110809(40),
r.reportOverseaPay(window.IAPProductInfo.currencyCode,100*window.IAPProductInfo.price.toFixed(2),1,window.IAPProductInfo.invokeTime,window.IAPProductInfo.countryCode,0,window.IAPProductInfo.err_msg+(window.IAPProductInfo.err_desc?"__"+window.IAPProductInfo.err_desc:""))):window.oriProductFee=Math.floor(e.fee/100)),
e.pay_cnt){
if(e.is_paid&&!c){
e.pay_head_imgs.unshift(e.my_head_img),e.reward_status_list instanceof Array?e.reward_status_list.unshift(e.my_reward_status):e.reward_status_list=[e.my_reward_status];
var w=3*h.perLine;
e.pay_head_imgs.length>w&&(e.pay_head_imgs=e.pay_head_imgs.slice(0,w));
}
e.rewardTotal=t.rewardTotal,e.rewardTotalCut=t.rewardTotalCut,h.data=e,s.wrap.style.height="",
s.wrap.style.marginTop="",s.wrap.style.visibility="visible",b(),!o&&j();
}else s.wrap.style.display="none";
if(s.giftBar)if(window.payGiftsCount-e.gifted_count>0&&!c){
s.giftBar.style.display="";
var f=window.localStorage.getItem("paySuc"),u=h.dom.giftBar.getBoundingClientRect(),p=u.top;
"1"===f&&p>window.innerHeight?!function(){
window.localStorage.setItem("paySuc","0"),h.dom.giftBar.className="pay__gift-send show",
h.dom.giftBarTitle.innerText="已购买，可赠送给一位朋友",l(2);
var e=8+window.parseInt(window.getComputedStyle(document.documentElement).getPropertyValue("--sab")),t=0,a=0,o=!1,r=0,s=function(e){
n.hasClass(h.dom.giftBar,"show")&&(o=!0,r=e.touches[0].clientY,t=a);
},d=function(i){
i.preventDefault();
var s=i.touches[0].clientY,d=s-r;
n.hasClass(h.dom.giftBar,"show")&&o&&(d+t>=0&&e>=d+t?(h.dom.giftBar.style.transform="translate3d(0, "+(d+t)+"px, 0)",
a=d+t):d+t>e?(h.dom.giftBar.style.transform="translate3d(0, "+e+"px, 0)",a=e):0>d+t&&(h.dom.giftBar.style.transform="translate3d(0, 0, 0)",
a=0));
},w=function p(){
o=!1,n.hasClass(h.dom.giftBar,"show")&&a===e&&(h.dom.giftBar.className="pay__gift-send",
i.off(h.dom.giftBar,"touchstart",s),i.off(h.dom.giftBar,"touchmove",d),i.off(h.dom.giftBar,"touchend",p));
},c=window.scrollY,f=window.innerHeight/3,u=function _(){
var e=h.dom.wrap.getBoundingClientRect(),t=e.top+e.height-48;
t<=window.innerHeight?(h.dom.giftBarTitle.innerText="可赠送给一位朋友免费阅读",h.dom.giftBar.className="pay__gift-send pay__gift-send_static",
h.dom.giftBar.style.transform="translate3d(0, 0, 0)",i.off(h.dom.giftBar,"touchstart",s),
i.off(h.dom.giftBar,"touchmove",d),i.off(h.dom.giftBar,"touchend",w),i.off(window,"scroll",_),
l(4)):window.scrollY-c>f&&(h.dom.giftBar.className="pay__gift-send");
};
i.on(window,"scroll",u),i.on(h.dom.giftBar,"touchstart",s),i.on(h.dom.giftBar,"touchmove",d),
i.on(h.dom.giftBar,"touchend",w);
}():!n.hasClass(h.dom.giftBar,"show")&&p<=window.innerHeight&&(h.dom.giftBar.className="pay__gift-send pay__gift-send_static",
l(4));
}else s.giftBar.style.display="none";
s.sendTips&&!function(){
var e=function t(){
return d.checkExposedStatus(s.sendTips)?(console.log("report send tips."),l(1),i.off(window,"scroll",t),
!0):!1;
};
e()||i.on(window,"scroll",e);
}();
}
},I=function(){
if(!window.isPaySubscribe)return 0;
if(null===h.perLine){
var e=m+g;
h.perLine=Math.floor(.8*f/e),h.dom.wall.parentNode.style.width=h.perLine*e-g+"px";
}
return h.perLine;
};
return{
init:B,
getCountPerLine:I
};
});define("appmsg/reward_utils.js",["biz_wap/ui/weui.js","appmsg/reward_entry.js","biz_wap/utils/mmversion.js","biz_common/dom/class.js","biz_common/dom/event.js"],function(e){
"use strict";
e("biz_wap/ui/weui.js");
var r=e("appmsg/reward_entry.js"),n=e("biz_wap/utils/mmversion.js"),i=e("biz_common/dom/class.js"),a=e("biz_common/dom/event.js"),t=window.navigator.userAgent,d={
perLine:0,
hasBindResize:!1,
hasInit:!1,
pageContainerId:"img-content",
rewardInnerId:"js_reward_inner"
},s=function(e){
return document.getElementById(e);
},o=function(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0],r=e.pageContainerId||d.pageContainerId,n=e.rewardInnerId||d.rewardInnerId,i=window.innerWidth||document.documentElement.clientWidth;
try{
var a=s(r).getBoundingClientRect();
a.width&&(i=a.width);
}catch(t){}
var o=36;
d.perLine=Math.floor(.8*i/o);
var w=s(n);
return w&&(w.style.width=d.perLine*o+"px"),d.perLine;
},w=function(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0],n=e.pageContainerId||d.pageContainerId,i=e.rewardInnerId||d.rewardInnerId;
return e.can_reward&&s(n)&&s(i)?(d.hasBindResize||!function(){
d.hasBindResize=!0;
var n=window.innerWidth;
a.on(window,"resize",function(){
window.innerWidth!==n&&(n=window.innerWidth,o(e),d.hasInit&&r.render(d.perLine));
});
}(),d.perLine||o(e),d.perLine):0;
},_=function(e,o){
d.hasInit=!0;
var _=e.author_id||window.author_id;
e.reward_head_imgs=e.reward_head_imgs||[];
var m=s("js_author_name");
if(o.reward_entrance_enable_for_preview)if(n.isInMiniProgram)n.isInMiniProgram&&m&&i.removeClass(m,"rich_media_meta_link");else{
if(_||n.isAndroid){
var u=s("js_preview_reward_author");
u&&(u.style.display="block");
var p=s("js_preview_reward_author_wording");
o.reward_wording&&p&&(p.innerText=o.reward_wording,p.style.display="block");
var h=s("js_preview_reward_author_link");
h&&(window.item_show_type&&1*window.item_show_type===5||a.on(h,"tap",function(e){
e.preventDefault(),window.weui.alert("预览状态下无法操作");
}));
}
if(_){
var l=s("js_preview_reward_author_avatar"),c=s("js_preview_reward_author_head");
o.reward_author_head&&l&&c&&(c.setAttribute("src",o.reward_author_head),l.style.display="block");
var v=s("js_preview_reward_link_text");
v&&(v.innerText="喜欢作者");
}else n.isAndroid&&(s("js_preview_reward_author_name").style.display="none");
}else!n.isInMiniProgram&&(t.indexOf("WindowsWechat")>-1||n.isIOS||n.isAndroid)?(r.handle(e,w({
pageContainerId:o.pageContainerId,
rewardInnerId:o.rewardInnerId,
can_reward:1==e.can_reward?!0:!1
})),m&&e.rewardsn&&e.timestamp&&(m.setAttribute("data-rewardsn",e.rewardsn),m.setAttribute("data-timestamp",e.timestamp),
m.setAttribute("data-canreward",e.can_reward)),m&&!e.can_reward&&i.removeClass(m,"rich_media_meta_link")):m&&i.removeClass(m,"rich_media_meta_link");
};
return{
init:_,
getCountPerLine:w
};
});define("biz_common/ui/imgonepx.js",[],function(){
"use strict";
return"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAIAAACQd1PeAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyBpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMC1jMDYwIDYxLjEzNDc3NywgMjAxMC8wMi8xMi0xNzozMjowMCAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENTNSBXaW5kb3dzIiB4bXBNTTpJbnN0YW5jZUlEPSJ4bXAuaWlkOkJDQzA1MTVGNkE2MjExRTRBRjEzODVCM0Q0NEVFMjFBIiB4bXBNTTpEb2N1bWVudElEPSJ4bXAuZGlkOkJDQzA1MTYwNkE2MjExRTRBRjEzODVCM0Q0NEVFMjFBIj4gPHhtcE1NOkRlcml2ZWRGcm9tIHN0UmVmOmluc3RhbmNlSUQ9InhtcC5paWQ6QkNDMDUxNUQ2QTYyMTFFNEFGMTM4NUIzRDQ0RUUyMUEiIHN0UmVmOmRvY3VtZW50SUQ9InhtcC5kaWQ6QkNDMDUxNUU2QTYyMTFFNEFGMTM4NUIzRDQ0RUUyMUEiLz4gPC9yZGY6RGVzY3JpcHRpb24+IDwvcmRmOlJERj4gPC94OnhtcG1ldGE+IDw/eHBhY2tldCBlbmQ9InIiPz6p+a6fAAAAD0lEQVR42mJ89/Y1QIABAAWXAsgVS/hWAAAAAElFTkSuQmCC";
});