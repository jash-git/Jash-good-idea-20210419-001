var _extends=Object.assign||function(e){
for(var n=1;n<arguments.length;n++){
var t=arguments[n];
for(var s in t)Object.prototype.hasOwnProperty.call(t,s)&&(e[s]=t[s]);
}
return e;
};
define("question_answer/appmsg.js",["biz_common/utils/string/html.js","biz_wap/utils/ajax.js","biz_common/dom/event.js","pages/utils.js","biz_common/tmpl.js","question_answer/qa_card.html.js","question_answer/answer_item.html.js","question_answer/reply_item.html.js","question_answer/write_answer_reply.html.js","biz_common/utils/url/parse.js","biz_common/dom/class.js","pages/mod/bottom_modal.js","appmsg/emotion/emotion.js","appmsg/emotion/dom.js","common/comm_report.js","biz_wap/utils/device.js","common/utils.js","biz_common/dom/offset.js","biz_wap/utils/wapsdk.js"],function(e){
"use strict";
function n(e,n){
var t=arguments.length<=2||void 0===arguments[2]?0:arguments[2];
return e.getElementsByClassName(n)[t];
}
function t(e){
var n=void 0;
if(window.qnaCardData)try{
n=JSON.parse(window.qnaCardData);
var t=n.list;
if(t&&t.length)for(var s=0;s<t.length;s++)if(e===t[s].question_id)return t[s].qna_sn;
}catch(a){
console.error(a);
}
return"";
}
function s(e){
e&&(e.style.display="none");
}
function a(e){
e&&(e.style.display="block");
}
function o(e,n){
G.jsmonitor({
id:223326,
key:e,
value:n
});
}
function i(){
window.weui.topTips("系统错误，请稍后再试");
}
function r(){
return W.os.ios?1:W.os.android?2:-1;
}
function l(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0];
F.report(20883,_extends({
Device:r(),
MsgId:1*gn.mid,
ItemIdx:1*gn.idx,
BizUin:nn.biz,
ItemShowType:1*nn.itemShowType,
SessionId:nn.sessionId,
EnterId:1*nn.enterId,
Scene:1*nn.scene,
SubScene:1*nn.subScene,
QaId:K.dataset.id
},e));
}
function _(e,n,t){
var s={
replyListHtml:"",
replyList:document.createDocumentFragment()
};
return e&&e.reply_list&&e.reply_list.length&&(s.leftReplyCount=e.left_reply_cnt,
s.leftReplyTips="余下%s条回复".replace("%s",e.left_reply_cnt),e.reply_list.forEach(function(e){
e.canOp=t,e.content=e.content.htmlEncode(),e.content=R.encode(e.content),e.likeNumFormated=k.formatReadNum(e.like_num),
e.replyStatus=void 0===e.reply_status?1:e.reply_status,e.isLogin=V;
var n=document.createElement("div");
n.innerHTML=B.tmpl(P,e,!1),s.replyListHtml+=n.innerHTML,s.replyList.appendChild(n.firstChild);
})),s;
}
function d(e,n){
var t=arguments.length<=2||void 0===arguments[2]?"":arguments[2],s={
answerListHtml:"",
fragment:document.createDocumentFragment()
};
return e.forEach(function(e){
e.likeNumFormated=k.formatReadNum(e.like_num),e.canOp=n,e.answer_sn=e.answer_sn||"",
e.content=e.content.htmlEncode(),e.oriContent=e.content,e.content=R.encode(e.content),
e.isLogin=V;
var a=_(e.reply_info,e.answer_id,n,t);
_extends(e,a);
var o=document.createElement("div");
o.innerHTML=B.tmpl(x,e,!1),s.answerListHtml+=o.innerHTML,s.fragment.appendChild(o.firstChild);
}),t===un?sn+=cn:t===pn&&(tn+=cn),s;
}
function c(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0],n=_extends({
action:e.action,
limit:cn,
offset:e.offset
},gn);
H({
url:O.join("/mp/qna",n),
dataType:"json",
success:function(n){
var t=void 0;
n&&(t=n.qna_info?n.qna_info.answer_info:n.answer_info,e.successCb(t,n));
},
complete:function(){
e.complete&&e.complete();
}
});
}
function p(e,n){
for(var t=0;e.offsetParent&&e!==n;)t+=e.offsetTop,e=e.offsetParent;
return t;
}
function u(e,t,a){
var o=e.dataset.answerid,i=a?p(e,Y.getScrollEle()):0;
H({
url:O.join("/mp/qna",_extends({
action:"get_more_reply",
answer_id:o,
answer_sn:e.dataset.answersn,
limit:10
},gn)),
dataType:"json",
success:function(r){
if(r&&r.reply_info&&r.reply_info.reply_list&&r.reply_info.reply_list.length){
var l=_(r.reply_info,o,!0,t);
l.replyListHtml?(n(e.parentNode,"js_qa_reply_list").appendChild(l.replyList),l.leftReplyCount?e.innerHTML=l.leftReplyTips:s(e),
a&&Y.scrollTo(0,i-48)):s(e);
}
}
});
}
function m(e){
var t=n(Z,"js_get_more_reply_"+e);
t&&u(t,pn,!0);
}
function f(){
z.on(Z,"tap",".js_get_more_reply",function(e){
var n=e.delegatedTarget;
u(n,pn);
});
}
function w(){
return n(en,"js_qa_input");
}
function g(){
var e=w();
return(e.value||e.innerHTML).trim();
}
function y(){
g()?$.enableBtn():$.disableBtn();
}
function v(){
var e=w();
z.on(en,"tap",".js_get_more_reply",function(e){
var n=e.delegatedTarget;
u(n,un);
}),z.on(e,"input",y),z.on(e,"tap",function(){
$.scrollTo(0,0);
});
}
function j(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0];
c({
action:e.action,
offset:e.offset,
successCb:function(t,s){
if(t&&t.answer_list&&t.answer_list.length){
var o=void 0,i=void 0;
"get_my_answer"===e.action?(o=un,i=en,a(n(en,"js_qa_write_head"))):(o=pn,i=Z);
var r=n(i,"js_qa_qna_answer_list");
r.appendChild(d(t.answer_list,!0,o).fragment);
}
e.cb&&e.cb(t,s);
}
});
}
function b(){
if(en){
var e="回复: %s".replace("%s",R.encode(dn)),t=n(en,"js_reply_top_content");
on?(t.innerHTML=e,a(t)):s(t);
}
}
function h(e){
n(en,"js_alert_toast_word").innerHTML=e,a(n(en,"js_alert_toast")),setTimeout(function(){
s(n(en,"js_alert_toast"));
},800);
}
function q(){
for(var e=0,n=Z.getElementsByClassName("js_qa_list_item"),t=0;t<n.length&&n[t].getBoundingClientRect().y<Q.getInnerHeight();t++)e++;
e>an&&(an=e);
}
function T(e,t){
if(Y)return Y.show(),void(e&&t&&m(t));
var a=void 0;
Z=K.firstChild.cloneNode(!0);
var o=n(Z,"qa__list-more"),i=n(Z,"js_qa_write_answer");
o&&s(o),i&&U.addClass(i,fn),n(Z,"js_qa_qna_answer_list").innerHTML="",Y=new D(Z,{
title:"读者讨论",
extClass:"qa__card",
onPullUpLoad:function(){
a>0&&(Y.showPullUpLoading(),j({
action:"get_more_answer",
offset:tn,
cb:function(e,n){
Y.hidePullUpLoading(),e.left_answer_cnt||0!==n.base_resp.ret?Y.finishPullUpLoad():Y.showEndLine();
}
}));
},
cb:function(){
j({
action:"get_more_answer",
offset:tn,
cb:function(s){
if(e&&t)m(t);else{
var o=X.dataset.count,i=n(Z,"js_qa_list_item",o),r=p(i,Y.getScrollEle());
Y.scrollTo(0,r-96);
}
a=s.left_answer_cnt,a||Y.showEndLine();
}
});
},
onScroll:function(){
q();
},
onHide:function(){
q(),l({
EventType:3,
Exposure:an
}),an=0;
}
}),Y.show(),f();
}
function L(){
var e=w(),n=e.cloneNode();
n.id="tmp_input",n.style.top=0,n.style.position="absolute",e.parentNode.insertBefore(n,e),
n.value=e.value,n.scrollTop=e.scrollTop;
}
function C(){
var e=document.getElementById("tmp_input");
e&&e.parentNode.removeChild(e);
}
function N(e){
var t=void 0,o=on?"写回复":"参与讨论";
return $?(b(),$.setTitle(o),$.setCloseBtnStyle(e?"back":"close"),void $.show(!0,wn,w(),{
afterTransparentInputEle:L,
afterShowInputEle:C
})):(en=document.createElement("div"),en.innerHTML=B.tmpl(M,{}),$=new D(en,{
title:o,
top:wn,
extClass:"qa__card qa__card_write",
hasBtn:!0,
disableTransition:!0,
innerScrollList:[w()],
onPullUpLoad:function(){
t>0&&($.showPullUpLoading(),j({
action:"get_my_answer",
offset:sn,
cb:function(e,n){
$.hidePullUpLoading(),e.left_answer_cnt||0!==n.base_resp.ret?$.finishPullUpLoad():$.showEndLine();
}
}));
},
onHide:function(){
w().blur();
},
onScroll:function(e){
"up"===e&&w().blur();
},
cb:function(){
j({
action:"get_my_answer",
offset:sn,
cb:function(e){
t=e.left_answer_cnt,t||$.showEndLine();
}
});
},
btnClickCb:function(){
$.disableBtn();
var e=on?"add_reply":"add_answer";
a(n(en,"js_loading_toast")),H({
url:"/mp/qna?action="+e,
type:"POST",
dataType:"json",
data:_extends({
answer_id:ln,
answer_sn:_n,
content:g(),
my_reply_cnt:rn+1,
ignore_tips:1
},gn),
success:function(e){
if(e&&e.base_resp&&0===e.base_resp.ret){
if(a(n(en,"js_sended_toast")),setTimeout(function(){
s(n(en,"js_sended_toast"));
},800),w().value="",$.disableBtn(),on&&e.reply_info&&e.reply_info.reply_list){
var t=_(e.reply_info,ln,!0).replyList,o=n(en,"js_qa_reply_list_"+ln);
o.appendChild(t.cloneNode(!0)),a(n(o.parentNode,"js_write_reply")),s(n(o.parentNode.parentNode,"js_write_reply"));
}else if(!on&&e.answer_info&&e.answer_info.answer_list){
var r=n(en,"js_qa_qna_answer_list");
r.insertBefore(d(e.answer_info.answer_list,!0).fragment,r.firstChild),a(n(en,"js_qa_write_head"));
}
}else $.enableBtn(),168003===e.base_resp.ret||168007===e.base_resp.ret?h("内容涉嫌违反平台协议或法规政策"):168004===e.base_resp.ret?h("关注该公众号才能参与讨论"):168005===e.base_resp.ret?h("关注该公众号3天及以上才能参与讨论"):168008===e.base_resp.ret||168009===e.base_resp.ret?h("字数不能多于"+(on?140:600)):i();
},
error:function(){
i(),$.enableBtn();
},
complete:function(){
s(n(en,"js_loading_toast")),w().blur();
}
});
}
}),b(),$.disableBtn(),$.setCloseBtnStyle(e?"back":"close"),$.show(!0,wn,w(),{
afterTransparentInputEle:L,
afterShowInputEle:C
}),v(),void new R.Emotion({
emotionPanel:A("#js_qa_emotion_panel"),
inputArea:A(w()),
emotionPanelArrowWrp:A("#js_qa_emotion_panel_arrow_wrp"),
emotionSwitcher:A("#js_qa_emotion_switch"),
emotionSlideWrapper:A("#js_qa_emotion_slide_wrapper"),
emotionNavBar:A("#js_qa_emotion_navbar"),
inputEmotion:function(){
y();
}
}));
}
function E(){
function e(){
if(!t){
var e=K.firstChild,n=J.getOffset(e).offsetTop,s=Q.getScrollTop();
s+Q.getInnerHeight()>=n&&s<=n+e.offsetHeight&&(l({
EventType:1
}),o("0"),t=!0);
}
}
var t=void 0;
z.on(K,"tap",".js_get_more_reply",function(e){
var n=e.delegatedTarget,t=n.dataset.answerid;
yn[t]?T():(T(!0,t),yn[t]=!0);
}),z.on(document.body,"click",".js_qa_write_answer",function(e){
on=!1,N(U.hasClass(e.delegatedTarget,fn)),o(2);
}),z.on(document.body,"click",".js_write_reply",function(e){
var t=e.delegatedTarget,s=t.parentNode.parentNode;
if(ln=t.dataset.answerid,_n=t.dataset.answersn,s){
var a=s.getElementsByClassName("js_qa_reply_content");
rn=s.getElementsByClassName("js_qa_my_reply").length,dn=a.length?a[a.length-1].innerHTML:n(s,"js_qa_item_content").innerHTML;
}
on=ln,on&&(N(!0),o(3));
}),z.on(X,"click",function(){
T(),l({
EventType:2
}),o(1);
}),z.on(document.body,"tap",".js_qa_like",function(e){
var t=e.delegatedTarget,s=U.hasClass(t,mn);
U.toggleClass(t,mn);
var a=n(t,"js_like_num"),i=parseInt(a.dataset.num,10)||0,r=i+(s?-1:1);
r=r>=0?r:0,a.innerHTML=k.formatReadNum(r),a.dataset.num=r,o("2"===t.dataset.type?6:5),
H({
url:"/mp/qna?action=like",
type:"POST",
data:_extends({
like_type:t.dataset.type,
op:s?2:1,
answer_id:t.dataset.id,
reply_id:t.dataset.id
},gn)
});
}),z.on(document.body,"tap",".js_delete_answer",function(e){
var n=e.delegatedTarget;
o(7),setTimeout(function(){
window.weui.confirm("确定删除讨论内容吗？",{
buttons:[{
label:"取消",
type:"default"
},{
label:"删除",
type:"primary",
onClick:function(){
H({
url:"/mp/qna?action=del_answer",
type:"POST",
dataType:"json",
data:_extends({
answer_id:n.dataset.id
},gn),
success:function(e){
if(e&&e.base_resp&&0===e.base_resp.ret){
var t=n.parentNode.parentNode.parentNode.parentNode;
t&&U.hasClass(t,"js_qa_list_item")&&t.parentNode.removeChild(t);
}else i();
}
});
}
}]
});
},50);
}),z.on(document.body,"tap",".js_delete_reply",function(e){
var t=e.delegatedTarget;
o(8),setTimeout(function(){
window.weui.confirm("确定删除回复吗？",{
buttons:[{
label:"取消",
type:"default"
},{
label:"删除",
type:"primary",
onClick:function(){
H({
url:"/mp/qna?action=del_reply",
type:"POST",
dataType:"json",
data:_extends({
reply_id:t.dataset.id
},gn),
success:function(e){
if(e&&e.base_resp&&0===e.base_resp.ret){
var o=t.parentNode.parentNode.parentNode;
if(o&&U.hasClass(o,"js_qa_reply_item")){
var r=o.parentNode;
r.removeChild(o),r.children.length||(s(r.parentNode),s(n(r.parentNode,"js_write_reply")),
a(n(r.parentNode.parentNode,"js_write_reply")));
}
}else i();
}
});
}
}]
});
},50);
}),Q.bindDebounceScrollEvent(e),e();
}
function S(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0];
gn.mid=e.mid,gn.idx=e.idx,nn.userUin=e.userUin,nn.biz=e.biz,nn.itemShowType=e.itemShowType,
nn.enterId=e.enterId,nn.scene=e.scene,nn.subScene=e.subScene,nn.sessionId=e.sessionId,
V=e.isLogin,c({
action:"get_qna_info",
successCb:function(e,t){
var s=void 0,a=void 0,i=void 0,r=void 0,l=t.base_resp.ret,_=168001===l,c=t.qna_info&&t.qna_info.question_info;
return _?void(K.innerHTML=B.tmpl(I,{
qaDeleted:_
})):void(0===l&&("1"===O.getQuery("js_my_answer")&&(N(),o(4)),e&&e.answer_list&&e.answer_list.length&&(i=d(e.answer_list,!1).answerListHtml,
a=e.answer_list.length,e.left_answer_cnt&&(s="余下%s条讨论内容".replace("%s",e.left_answer_cnt))),
1===c.can_answer_type&&0===t.qna_info.is_fans?r="作者已设置关注后才可参与讨论":2===c.can_answer_type&&0===t.qna_info.is_fans_days&&(r="作者已设置关注3天后才可参与讨论"),
K.innerHTML=B.tmpl(I,{
qaDeleted:_,
answerCount:a,
leftAnswerCnt:s,
answerListStr:i,
disableAnswerWord:r,
title:R.encode(c.question_title.htmlEncode()),
nickname:c.biz_info.nickname,
isLogin:V
}),X=n(K,"js_more_answer_entry"),E()));
}
});
}
e("biz_common/utils/string/html.js");
var H=e("biz_wap/utils/ajax.js"),z=e("biz_common/dom/event.js"),k=e("pages/utils.js"),B=e("biz_common/tmpl.js"),I=e("question_answer/qa_card.html.js"),x=e("question_answer/answer_item.html.js"),P=e("question_answer/reply_item.html.js"),M=e("question_answer/write_answer_reply.html.js"),O=e("biz_common/utils/url/parse.js"),U=e("biz_common/dom/class.js"),D=e("pages/mod/bottom_modal.js"),R=e("appmsg/emotion/emotion.js"),A=e("appmsg/emotion/dom.js"),F=e("common/comm_report.js"),W=e("biz_wap/utils/device.js"),Q=e("common/utils.js"),J=e("biz_common/dom/offset.js"),G=e("biz_wap/utils/wapsdk.js"),K=document.getElementsByTagName("mp-qa")[0];
if(!K)return{};
var V=void 0,X=void 0,Y=void 0,Z=void 0,$=void 0,en=void 0,nn={},tn=0,sn=0,an=0,on=void 0,rn=void 0,ln=void 0,_n=void 0,dn="",cn=10,pn="answerList",un="myAnswerList",mn="praised",fn="modalWriteAnswerClass",wn="25px",gn={
__biz:K.dataset.bizuin,
question_id:K.dataset.id,
qna_sn:t(K.dataset.id)
},yn={};
return{
renderQaCard:S
};
});define("appmsg/weapp.js",["biz_common/utils/string/html.js","pages/weapp_tpl.html.js","biz_wap/utils/ajax.js","biz_common/dom/event.js","biz_common/tmpl.js","biz_common/dom/class.js","biz_wap/utils/device.js","appmsg/weapp_common.js","common/utils.js","biz_wap/utils/mmversion.js","biz_common/base64.js","appmsg/popup_report.js","biz_wap/utils/jsmonitor_report.js"],function(e){
"use strict";
function t(e,t,n){
var o=new Image;
o.src=("http://mp.weixin.qq.com/mp/jsreport?1=1&key=106&content="+n+",biz:"+biz+",mid:"+mid+",uin:"+uin+"[key1]"+encodeURIComponent(t.toString())+"&r="+Math.random()).substr(0,1024);
}
function n(e,t,n,o,i,p,a){
h({
url:"/mp/appmsgreport?action=appmsg_weapp_report",
data:{
__biz:window.biz||"",
mid:window.mid||"",
idx:window.idx||"",
weapp_appid:e||"",
weapp_pos:t||0,
weapp_title:o||0,
weapp_nickname:n||0,
type:i||0,
scene:window.source||-1,
weapp_type:p,
is_confirm:a||0,
ascene:window.ascene||-1
},
type:"POST",
dataType:"json",
async:!0,
success:function(){}
});
}
function o(e){
var t=e.innerHTML,n=/<img.*src=[\'\"]/,o=/background-image:(\s*)url\(/,i=/background:[^;"']+url\(/;
return n.test(t)||o.test(t)||i.test(t)?!0:!1;
}
function i(e){
var t=e.innerHTML,n=e.style.fontSize;
return 0===t.trim().length||0===parseFloat(n)?!0:!1;
}
function p(){
var e=c("js_content");
if(!e)return!1;
z=e.getElementsByTagName("mp-weapp")||[],R=e.getElementsByTagName("mp-miniprogram")||[],
x=[];
for(var t=e.getElementsByTagName("a"),n=0,o=t.length;o>n;n++){
var i=t[n],p=i.getAttribute("data-miniprogram-appid");
p&&x.push(i);
}
return z.length<=0&&R.length<=0&&0==x.length?!1:T&&0!=T.length?!0:(window.__addIdKeyReport&&window.__addIdKeyReport("27613","52",1),
!1);
}
function a(e){
return e=e||"",e.replace(/&/g,"&amp;").replace(/</g,"&lt;").replace(/>/g,"&gt;").replace(/"/g,"&quot;");
}
function r(e,t,o,i,p){
n(e,t,o,i,4,p),window.__addIdKeyReport&&window.__addIdKeyReport("28307",103);
}
function d(e,t,o,i,p){
n(e,t,o,i,5,p);
}
function s(){
function e(e){
e.preventDefault();
}
function p(e){
e&&(l=setTimeout(function(){
e.style.display="none",c=-1;
},100));
}
window.reportWeappid=[];
for(var s=0;s<T.length;s++)window.reportWeappid.push(T[s].appid);
var m=function(){};
y.on(document.getElementById("js_minipro_dialog_ok"),"click",function(t){
t.stopPropagation(),t.preventDefault(),document.querySelector("body").removeEventListener("touchmove",e);
var n=document.getElementById("js_minipro_dialog");
m&&m(),document.getElementById("js_minipro_dialog").style.display="none",C.report([4,1,"",img_popup?1:0,window.source,n._appid]);
}),y.on(document.getElementById("js_minipro_dialog_cancel"),"click",function(t){
t.stopPropagation(),t.preventDefault(),document.querySelector("body").removeEventListener("touchmove",e);
var o=document.getElementById("js_minipro_dialog");
o.style.display="none",n(o._appid,o._i,o._nickname,o._title,3,1,1),window.__addIdKeyReport&&window.__addIdKeyReport("28307",116),
C.report([3,1,"",img_popup?1:0,window.source,o._appid]);
});
var l,c,h=j.os.pc,E=document.getElementById("js_pc_weapp_code"),z=document.getElementById("js_pc_weapp_code_img"),R=document.getElementById("js_pc_weapp_code_des");
h&&(y.on(E,"mouseenter",function(){
clearTimeout(l);
}),y.on(E,"mouseleave",function(){
p(E);
})),I.getAppidInfo({
onSuccess:function(j){
console.log("WeappCommon.getAppidInfo onsuccess");
var x=j.data.infoMap;
if(!x)return void(window.__addIdKeyReport&&window.__addIdKeyReport("27613","52",1));
for(s=0;s<B.length;s++)(function(s){
window.__addIdKeyReport("111535",1);
var k=B[s].appid,K=B[s].path,T=B[s].imageUrl,A=B[s].title,N=B[s].elem,S=x[k];
if(!S)return void(window.__addIdKeyReport&&window.__addIdKeyReport("27613","52",1));
var W=N.tagName.toLowerCase(),q=N.firstChild&&1==N.firstChild.nodeType&&"IMG"===N.firstChild.tagName;
if(q=q||N.firstElementChild&&"IMG"===N.firstElementChild.tagName,"a"!=W)N.innerHTML=v.tmpl(w,{
imageUrl:a(T),
title:a(A),
nickname:a(S.nickname),
avatar:a(S.logo_url)
},!1);else{
if(q){
var L=N.firstChild;
L&&b.addClass(N,"weapp_image_link");
}else b.addClass(N,"weapp_text_link");
N.setAttribute("href","");
}
if(j.resp&&j.resp.weapp_info&&j.resp.weapp_info.length)for(var M=0;M<j.resp.weapp_info.length;M++){
var U=N.getElementsByClassName("guarantee_icon")[0];
if(j.resp.weapp_info[M].weapp_appid===k&&1===j.resp.weapp_info[M].has_guarantee_flag){
U&&b.addClass(U,"show");
break;
}
}
y.on(N,"tap",function(){
if(m=function(){
var e=q?1:"a"==W?2:0;
return I.jumpUrl({
sceneNote:encodeURIComponent(location.href)+":"+window.biz,
appid:k,
path:K,
scene:window.__weapp_scene__||1058,
beforeNonWechatWarn:function(){
d(k,s,S.nickname,A,e);
},
beforeJumpBackupPage:function(){
r(k,s,S.nickname,A,e);
},
onJsapiCallback:function(e){
"openWeApp:ok"===e.err_msg&&window.__addIdKeyReport&&window.__addIdKeyReport("28307",102),
t(107,new Error(e.err_msg),"");
}
}),window.__addIdKeyReport&&window.__addIdKeyReport("28307",100),n(k,s,S.nickname,A,3,e,q?2:0),
q&&window.__addIdKeyReport&&window.__addIdKeyReport("28307",115),!1;
},q&&C.report([2,1,"",img_popup?1:0,window.source,k]),(q||b.hasClass(N,"weapp_text_link")&&(o(N)||i(N)))&&img_popup){
document.getElementById("js_minipro_dialog_head").innerText="即将打开小程序",document.getElementById("js_minipro_dialog_body").innerText=S.nickname;
var p=document.getElementById("js_minipro_dialog");
return p.style.display="block",document.querySelector("body").addEventListener("touchmove",e,{
passive:!1
}),p._appid=k,p._i=s,p._nickname=S.nickname,p._title=A,n(k,s,S.nickname,A,3,1,0),
I.canJumpOnTap&&window.__addIdKeyReport&&window.__addIdKeyReport("28307",114),!1;
}
return m();
},"a"==W),y.on(N,"click",function(e){
e.preventDefault(),e.stopPropagation();
},"a"==W),h&&(y.on(N,"mouseenter",function(){
function e(e){
function t(){
if(!l&&c===s){
E.style.display="block",l=!0;
var e=E.offsetHeight,t=E.offsetWidth;
"a"!=W||q?n>t?(f(E,"right-center"),E.style.left=n-t-m+"px",E.style.top=o+"px"):(f(E),
E.style.top=o+d-e-m+"px",E.style.left=n+r-t-m+"px"):(E.style.left=i>n+r/2-t/2?i+"px":n+r/2+t/2>i+p?i+p-t+"px":n+r/2-t/2+"px",
a>e?(f(E,"down-center"),E.style.top=o-e-m+"px"):(f(E,"up-center"),E.style.top=o+d-m+"px"));
}
}
if(e){
var n=u(N),o=_(q?N.firstElementChild:N),i=u(N.parentNode),p=N.parentNode.offsetWidth,a=N.getBoundingClientRect().top,r=q?N.firstElementChild.offsetWidth:N.offsetWidth,d=q?N.firstElementChild.offsetHeight:N.offsetHeight,m=8,l=!1;
R.innerText=g(S.nickname,48),z.onload=t,z.src=e,(z.complete||z.width)&&t();
}
}
clearTimeout(l),c!==s&&(E.style.display="none",c=s,I.getAppidCode({
appid:k,
path:K
},e));
}),y.on(N,"mouseleave",function(){
p(E);
}));
})(s);
var K=null,T=function(){
K=null;
for(var e=0;e<A.length;e++){
var t=A[e].elem,o=t.tagName.toLowerCase(),i=t.firstChild&&1==t.firstChild.nodeType,p=i?1:"a"==o?2:0,a=A[e].elem.getBoundingClientRect();
if(a.top<k.getInnerHeight()&&a.bottom>0){
setTimeout(function(){
window.__addIdKeyReport&&window.__addIdKeyReport("28307",101);
},0);
var r=A[e].appid;
r&&x[r]&&x[r].nickname&&n(r,e,x[r].nickname,A[e].title,2,p),A.splice(e--,1);
}
}
};
T(),y.on(window,"scroll",function(){
K||(K=setTimeout(T,100));
});
},
onError:function(e){
3==e.code&&t(106,e.catchErr,"parsing weapp info error");
}
});
}
function m(){
for(var e=0,t=0;t<R.length+z.length;t++){
var n=t<R.length,o=n?R[t]:z[t-R.length],i=o.getAttribute(n?"data-miniprogram-appid":"data-weapp-appid")||"",p=o.getAttribute(n?"data-miniprogram-path":"data-weapp-path")||"",a=o.getAttribute(n?"data-miniprogram-imageUrl":"data-weapp-imageUrl")||"",r=o.getAttribute(n?"data-miniprogram-title":"data-weapp-title")||"",d=document.createElement("span");
o.setAttribute("class",""),d.setAttribute("class","weapp_display_element js_weapp_display_element"),
B.push({
appid:i,
path:p,
imageUrl:a,
title:r,
elem:d
}),A.push({
appid:i,
elem:d,
title:r
}),o.parentNode.insertBefore(d,o.nextSibling),l(a)||e++;
}
for(var t=0;t<x.length;t++){
var s=x[t];
B.push({
appid:s.getAttribute("data-miniprogram-appid"),
path:s.getAttribute("data-miniprogram-path")||"",
elem:s
});
}
e>0&&E.setSum(64469,33,e);
}
function l(e){
for(var t,n=[/^http(s)?:\/\/mmbiz\.qpic\.cn([\/?].*)*$/i,/^http(s)?:\/\/mmbiz\.qlogo\.cn([\/?].*)*$/i,/^http(s)?:\/\/mmsns\.qpic\.cn([\/?].*)*$/i],o=0;t=n[o++];)if(t.test(e))return!0;
return!1;
}
function c(e){
return document.getElementById(e);
}
function u(e){
for(var t=0;e;)t+=e.offsetLeft,e=e.offsetParent;
return t;
}
function _(e){
for(var t=0;e;)t+=e.offsetTop,e=e.offsetParent;
return t;
}
function f(e,t){
for(var n=0;3>n;n++)b.removeClass(e,"weui-desktop-popover_pos-up-"+N[n]),b.removeClass(e,"weui-desktop-popover_pos-down-"+N[n]),
b.removeClass(e,"weui-desktop-popover_pos-left-"+S[n]),b.removeClass(e,"weui-desktop-popover_pos-right-"+S[n]);
b.removeClass(e,"weui-desktop-popover_hide-arrow"),t?b.addClass(e,"weui-desktop-popover_pos-"+t):b.addClass(e,"weui-desktop-popover_hide-arrow");
}
function g(e,t){
var n=/[^\x00-\xff]/g;
if(e.replace(n,"**").length>t)for(var o=Math.floor(t/2),i=o,p=e.length;p>i;i++)if(e.substring(0,i).replace(n,"**").length>=t)return e.substring(0,i)+"...";
return e;
}
e("biz_common/utils/string/html.js");
var w=e("pages/weapp_tpl.html.js"),h=e("biz_wap/utils/ajax.js"),y=e("biz_common/dom/event.js"),v=e("biz_common/tmpl.js"),b=e("biz_common/dom/class.js"),j=e("biz_wap/utils/device.js"),I=e("appmsg/weapp_common.js"),k=e("common/utils.js"),C=(e("biz_wap/utils/mmversion.js"),
e("biz_common/base64.js"),e("appmsg/popup_report.js")),E=e("biz_wap/utils/jsmonitor_report.js"),z=null,R=null,x=null,K={},B=[],T=I.appidSnInfo,A=[];
if(p()){
m(),s();
var N=["left","center","right"],S=["top","center","bottom"];
return K;
}
});define("appmsg/weproduct.js",["appmsg/weapp_common.js","biz_common/dom/event.js","biz_wap/utils/ajax.js","biz_common/utils/url/parse.js","biz_wap/utils/jsmonitor_report.js","common/utils.js"],function(t){
"use strict";
function e(){
if(console.log("weproduct init"),"function"==typeof document.getElementsByClassName){
var t=document.getElementsByClassName("js_product_container");
t&&t.length>0&&(a(t),d.getAppidInfo({
onSuccess:function(e){
g.data=e.data,o(t);
}
})),r();
}
}
function a(t){
try{
for(var e=0,a=t.length;a>e;e++){
var o=t[e];
if(o.className.indexOf("js_list_container")>=0){
var i=o.querySelector("img.js_cover");
if(i){
var r=i.parentNode.getBoundingClientRect();
i.style.setProperty("width",r.width+"px","important"),i.style.setProperty("height",r.height+"px","important"),
i.style.setProperty("background-size","unset","important"),"0"==i.getAttribute("data-fail")?n.call(i):i.getAttribute("data-fail")||(i.lazyLoadOnload=i.lazyLoadOnload||[],
i.lazyLoadOnload.push(n));
}
}
}
}catch(p){}
}
function n(){
var t=this.parentNode;
if(t){
var e=document.createElement("span");
e.className=this.className,e.style.background='url("'+this.src+'") no-repeat center',
t.insertBefore(e,this),t.removeChild(this);
}
}
function o(t){
for(var e=0,a=t.length;a>e;e++)!function(t,e){
s.on(t,"tap",".js_product_loop_content",function(t){
var a=t.delegatedTarget,n=a.getAttribute("data-wxaappid"),o=a.getAttribute("data-wxapath"),i=a.getAttribute("data-pid"),r=a.getAttribute("data-appid");
return d.jumpUrl({
privateExtraData:{
cookies:"cps_package=123456; expires=1538286412; busid=mmbiz_ad_cps; domain=*"
},
sourceAppId:r,
appid:n,
path:o,
scene:1091,
sceneNote:encodeURIComponent(location.href)+":"+encodeURIComponent(i),
beforeNonWechatWarn:function(){},
beforeJumpBackupPage:function(){},
onJsapiCallback:function(t){
if("openWeApp:ok"===t.err_msg&&i){
var o=a.getAttribute("data-pidtype"),r=2;
2==o&&(r=4),p([{
wxa_appid:n,
pid:i,
type:r,
absolute_order:e+1,
appid:a.getAttribute("data-appid")||"",
templateid:a.getAttribute("data-templateid")||"",
relative_order:1*a.getAttribute("data-order"),
packid:a.getAttribute("data-packid")||""
}]);
}
}
}),!1;
});
}(t[e],e);
var n=document.getElementsByClassName("js_product_loop_content");
if(n&&n.length>0&&m.getInnerHeight()){
for(var e=0;e<n.length;e++)g.pvele.push(n[e]);
i(),s.on(window,"scroll",i);
}
}
function i(){
g.checkInScreenId&&clearTimeout(g.checkInScreenId),g.checkInScreenId=setTimeout(function(){
g.checkInScreenId=null;
for(var t=[],e=0;e<g.pvele.length;e++){
var a=g.pvele[e],n=a.getBoundingClientRect(),o=n.height||n.bottom-n.top;
if(o>0&&n.top<m.getInnerHeight()&&n.bottom>0){
var r=a.getAttribute("data-pid");
if(r){
var d=a.getAttribute("data-pidtype"),c=1;
2==d&&(c=3),t.push({
wxa_appid:a.getAttribute("data-wxaappid"),
pid:r,
type:c,
absolute_order:e+1,
appid:a.getAttribute("data-appid")||"",
templateid:a.getAttribute("data-templateid")||"",
relative_order:1*a.getAttribute("data-order"),
packid:a.getAttribute("data-packid")||""
});
}
g.pvele.splice(e--,1);
}
}
p(t),0==g.pvele.length&&(s.off(window,"scroll",i),i=null);
},100);
}
function r(){
setTimeout(function(){
var t=document.getElementsByClassName("js_product_loop_content").length,e=document.getElementsByClassName("js_product_err_container").length;
u.setSum("64469","15",t+e),u.setSum("64469","16",t),u.setSum("64469","18",e);
},0);
}
function p(t){
if(t&&0!=t.length){
for(var e={
batch_no:l.getQuery("batch_no")||"",
bizuin:window.biz||"",
biz:window.biz||"",
mid:window.mid||"",
idx:window.idx||"",
total:t.length
},a=0;a<t.length;a++){
var n=t[a],o=a+1;
for(var i in n)n.hasOwnProperty(i)&&(e[i+""+o]=n[i]);
}
c({
url:"/mp/productreport?",
type:"POST",
data:e,
dataType:"json",
async:!0
});
}
}
var d=t("appmsg/weapp_common.js"),s=t("biz_common/dom/event.js"),c=t("biz_wap/utils/ajax.js"),l=t("biz_common/utils/url/parse.js"),u=t("biz_wap/utils/jsmonitor_report.js"),m=t("common/utils.js"),g={
pvele:[],
checkInScreenId:null,
reportRandom:Math.random()
};
e();
});define("appmsg/voicemsg.js",["biz_wap/ui/weui.js","biz_wap/jsapi/core.js","biz_wap/utils/ajax.js","pages/voice_component.js"],function(e){
"use strict";
e("biz_wap/ui/weui.js");
var i=e("biz_wap/jsapi/core.js"),t=e("biz_wap/utils/ajax.js"),o=e("pages/voice_component.js"),n=document.getElementById("js_read_container"),a={
player:null,
srcId:"__wxtag__"+window.biz+"-"+window.mid+"-"+window.idx,
mediaId:"",
tag:"===mediaId-sep===",
playDuration:0,
playTime:0,
maxNum:5,
curNum:0,
format:"",
type:6,
speed:100,
voiceInfo:{
title:"",
nickname:"",
appmsgUrl:"",
duration:0
},
voiceOpt:null,
lock:!1,
status:"stop",
currentTime:0,
beginTime:0,
leaveNeedReport:!1,
pause2PlayNeedReport:!1,
isSeek:!1,
loadingTimer:null
},s=function(e){
return e+"&uin="+window.uin+"&key="+window.key+"&pass_ticket="+encodeURIComponent(window.pass_ticket);
},d=function(e){
return e||null===a.loadingTimer?void i.invoke("handleMPPageAction",{
action:"showToast",
status:e?"loading":"dismissloading"
}):(clearTimeout(a.loadingTimer),void(a.loadingTimer=null));
},r=function c(){
if(a.curNum>10)return d(!1),a.lock=!1,void weui.alert("系统繁忙，请稍后再试");
a.curNum++;
var e=a.curNum>a.maxNum?5e3:1e3;
t({
url:"/mp/msgvoice?action=getvoiceinfo&__biz="+window.biz+"&mid="+window.mid+"&idx="+window.idx+"&sn="+window.sn+"&type="+a.type+"&speed="+a.speed,
type:"GET",
dataType:"json",
async:!0,
success:function(i){
if(i&&i.base_resp&&0===i.base_resp.ret)if(i.mediaid){
a.mediaId=i.mediaid;
var t=encodeURIComponent("__biz="+window.biz+"&mid="+window.mid+"&idx="+window.idx),o=a.voiceInfo;
a.voiceOpt={
protocol:2===i.format?"hls":"",
src:s("https://mp.weixin.qq.com/mp/msgvoice?action=get_voice&mediaid="+i.mediaid+"&devicetype="+window.devicetype+"&_type="+a.type+"&speed="+a.speed+"&encodeurl="+t),
lowbandUrl:s("https://mp.weixin.qq.com/mp/msgvoice?action=get_voice&mediaid="+i.mediaid+"&devicetype="+window.devicetype+"&_type="+a.type+"&speed="+a.speed+"&encodeurl="+t),
title:o.title,
epname:"来自文章",
singer:o.nickname?"的语音":"公众号语音",
srcId:a.srcId+a.tag+a.mediaId,
coverImgUrl:"",
webUrl:o.appmsgUrl,
musicbar_url:"https://mp.weixin.qq.com/mp/msgvoice?action=ttspage&__biz="+window.biz+"&mid="+window.mid+"&idx="+window.idx+"&sn="+window.sn+"&type="+a.type+"#wechat_redirect",
needStartMusicUI:0
},m();
}else setTimeout(c,1e3);else console.log("getvoiceinfo err",i),setTimeout(c,e);
},
error:function(i){
console.log("getvoiceinfo err",i),setTimeout(c,e);
}
});
},m=function(){
a.player=o.init({
protocal:"hls",
wxIndex:a.voiceOpt.srcId,
type:7,
comment_id:"",
src:a.voiceOpt.src,
jsapi2Src:a.voiceOpt.src+"&voice_type=1",
allowPause:!0,
duration:a.voiceInfo.duration,
title:a.voiceOpt.title,
singer:a.voiceOpt.singer,
epname:a.voiceOpt.epname,
coverImgUrl:a.voiceOpt.coverImgUrl,
playingCss:"share_audio_playing",
playCssDom:n.getElementsByClassName("js_read_main")[0],
playArea:n.getElementsByClassName("js_read_play")[0],
progress:n.getElementsByClassName("js_read_progress")[0],
fileSize:0,
playtimeDom:n.getElementsByClassName("js_read_playtime")[0],
bufferDom:n.getElementsByClassName("js_read_buffer")[0],
playdotDom:n.getElementsByClassName("js_read_playdot")[0],
seekRange:n.getElementsByClassName("js_read_seekRange")[0],
seekContainer:n.getElementsByClassName("js_read_main")[0],
loadingDom:n.getElementsByClassName("js_read_loading")[0],
detailArea:"",
detailUrl:a.voiceOpt.musicbar_url,
webUrl:a.voiceOpt.musicbar_url
});
};
t({
url:"/mp/msgvoice?action=ttspage&__biz="+window.biz+"&mid="+window.mid+"&idx="+window.idx+"&sn="+window.sn+"&type="+a.type+"&f=json",
type:"GET",
dataType:"json",
async:!0,
success:function(e){
e&&e.base_resp&&0===e.base_resp.ret?(a.voiceInfo={
title:e.title,
nickname:e.nickname,
appmsgUrl:e.appmsg_url,
duration:1*e.voice_info.duration
},r(),n.getElementsByClassName("js_read_duration")[0].innerHTML=function(e){
var i=function(e){
return e>=10?e:"0"+e;
};
return i(Math.floor(e/60))+":"+i(e%60);
}(1*e.voice_info.duration)):weui.alert("系统繁忙，请稍后再试");
},
error:function(e){
console.log("ttspage err: ",e),weui.alert("网络不可用，请检查网络设置");
}
});
});define("appmsg/autoread.js",["biz_common/utils/string/html.js","biz_common/dom/event.js","pages/voice_tpl.html.js","pages/voice_component.js","biz_wap/utils/ajax.js"],function(e){
"use strict";
function i(){
var e=d("autoread");
e&&(e.innerHTML='<p><label>朗读类型：</label>                                <select id="autoreadSelect">                                <option selected="true" value="0">女1</option>                                <option value="1">女2</option>                                <option value="2">男1</option>                                <option value="6">男2</option>                                </select></p><p id="autoread_voice"></p>',
r.on(d("autoreadSelect"),"change",function(){
p.player&&(p.player.destory(),p.player=null),p.checkAudioId&&(clearTimeout(p.checkAudioId),
p.checkAudioId=null);
var e=d("autoreadSelect");
d("autoread_voice").innerHTML="",o(e.value);
}),o(0));
}
function o(e){
var i=d("autoread_voice");
p._oMusic={
voiceid:p.voiceid,
duration_str:"",
posIndex:p.posIndex,
title:"文章朗读体验（"+p.voiceType[e||0]+"）",
nickname:window.nickname||"公众号"
},s.renderPlayer(u,p._oMusic,i,!0),d("voice_author_"+p.key).innerHTML="来自"+p._oMusic.nickname+"（创建音频中）",
c(e);
}
function n(e,i){
var o=p._oMusic;
d("voice_author_"+p.key).innerHTML="来自"+o.nickname,d("voice_duration_"+p.key).innerHTML=s.formatTime(1*i),
p.player=s.init({
protocal:"hls",
wxIndex:o.posIndex,
type:2,
songId:e,
src:a("https://mp.weixin.qq.com/mp/msgvoice?action=get_voice&media="+e),
allowPause:!0,
autoPlay:!0,
duration:i,
title:o.title,
singer:o.nickname?o.nickname+"的语音":"公众号语音",
epname:"来自文章",
coverImgUrl:window.__appmsgCgiData.hd_head_img,
playingCss:"share_audio_playing",
playCssDom:d("voice_main_"+p.key),
playArea:d("voice_play_"+p.key),
progress:d("voice_progress_"+p.key),
fileSize:o.fileSize,
playtimeDom:d("voice_playtime_"+p.key),
bufferDom:d("voice_buffer_"+p.key),
playdotDom:d("voice_playdot_"+p.key),
seekRange:d("voice_seekRange_"+p.key),
seekContainer:d("voice_main_"+p.key),
loadingDom:d("voice_loading_"+p.key)
});
}
function t(e){
p.curNum+=1;
var i=1e3;
p.curNum>p.maxNum&&(i=2e3);
var o=["/mp/msgvoice?action=get_media&mid=",window.mid||"","&idx=",window.idx||"","&biz=",window.biz||"","&type=",e||0].join("");
m({
url:o,
type:"GET",
dataType:"json",
async:!0,
success:function(o){
o.mediaid&&o.duration?n(o.mediaid,o.duration):p.checkAudioId=setTimeout(function(){
t(e);
},i);
},
error:function(){
p.checkAudioId=setTimeout(function(){
t(e);
},i);
}
});
}
function a(e){
return e+=["&mid=",window.mid||"","&idx=",window.idx||"","&biz=",window.biz||"","&uin=",window.uin||"","&key=",window.key||"","&pass_ticket=",window.pass_ticket||"","&clientversion=",window.clientversion||"","&devicetype=",window.devicetype||"","&wxtoken=",window.wxtoken||""].join("");
}
function c(e){
p.curNum=0;
var i=["/mp/msgvoice?action=tts&mid=",window.mid||"","&idx=",window.idx||"","&biz=",window.biz||"","&type=",e||0].join("");
m({
url:i,
type:"GET",
dataType:"json",
async:!0,
success:function(i){
i&&i.base_resp&&0==i.base_resp.ret?t(e):d("voice_author_"+p.key).innerHTML="来自"+window.nickname+"（失败）";
},
error:function(){
d("voice_author_"+p.key).innerHTML="来自"+window.nickname+"（失败）";
}
});
}
function d(e){
return document.getElementById(e);
}
e("biz_common/utils/string/html.js");
var r=e("biz_common/dom/event.js"),u=e("pages/voice_tpl.html.js"),s=e("pages/voice_component.js"),m=e("biz_wap/utils/ajax.js"),p={
checkId:"",
voiceid:"autoread",
posIndex:0,
key:"autoread_0",
voiceType:{
0:"女1",
1:"女2",
2:"男1",
6:"男2"
},
maxNum:5,
curNum:0
};
i();
});var _extends=Object.assign||function(t){
for(var e=1;e<arguments.length;e++){
var o=arguments[e];
for(var n in o)Object.prototype.hasOwnProperty.call(o,n)&&(t[n]=o[n]);
}
return t;
};
define("appmsg/poi/poi.js",["biz_common/utils/string/html.js","appmsg/poi/poi_tpl.html.js","biz_common/dom/event.js","biz_wap/jsapi/core.js","biz_common/tmpl.js","common/utils.js","pages/player_tips.js","biz_wap/utils/mmversion.js","common/comm_report.js","biz_wap/utils/jsmonitor_report.js","biz_common/base64.js"],function(t){
"use strict";
t("biz_common/utils/string/html.js");
var e=t("appmsg/poi/poi_tpl.html.js"),o=t("biz_common/dom/event.js"),n=t("biz_wap/jsapi/core.js"),i=t("biz_common/tmpl.js"),a=t("common/utils.js"),r=t("pages/player_tips.js"),d=t("biz_wap/utils/mmversion.js"),s=t("common/comm_report.js"),m=t("biz_wap/utils/jsmonitor_report.js"),p=t("biz_common/base64.js"),c={
tagName:"mppoi",
isWechat:(d.isAndroid||d.isIOS)&&d.isWechat&&!d.isWxwork,
screen_height:a.getInnerHeight(),
commonReportData:{
bizuin:1*p.decode(window.biz),
msgid:1*window.mid,
itemidx:1*window.idx,
sessionidnew:window.sessionid,
enterid:1*window.enterid
},
poiDom:[]
},u=function(){
return document.documentElement.scrollTop||document.body.scrollTop;
},l=function(t){
c.isWechat?n.invoke("openLocation",{
latitude:1*t.latitude,
longitude:1*t.longitude,
name:t.name,
address:t.address,
infoUrl:""
},function(t){
-1!==t.err_msg.indexOf("ok")?m.setSum(110809,53,1):m.setSum(110809,54,1);
}):new r({
msg:"请使用移动端微信打开。"
});
},g=function(){
var t=arguments.length<=0||void 0===arguments[0]?{}:arguments[0],e=t.dom,n=t.poiInfo;
o.on(e,"tap",function(t){
t.stopPropagation(),t.preventDefault(),s.report(19937,_extends({},c.commonReportData,{
type:2,
actiontype:2
})),m.setSum(110809,55,1),l(n);
},!0),o.on(e,"click",function(t){
t.preventDefault(),t.stopPropagation();
},!0);
},f=function(){
for(var t=0;t<c.poiDom.length;t++){
var e=c.poiDom[t];
if(1*e.getAttribute("data-hasreport")!==1){
e.setAttribute("data-hasreport",1);
var o=u();
e.clientHeight+e.offsetTop>=o+e.clientHeight/2&&e.clientHeight+e.offsetTop<=o+e.clientHeight/2+c.screen_height&&("A"===e.tagName?(s.report(19937,_extends({},c.commonReportData,{
type:1,
actiontype:1
})),m.setSum(110809,58,1)):(s.report(19937,_extends({},c.commonReportData,{
type:2,
actiontype:1
})),m.setSum(110809,56,1)));
}
}
};
o.on(window,"scroll",f);
var b=function(){
var t=arguments.length<=0||void 0===arguments[0]?{}:arguments[0];
t.node&&t.data&&t.data.img&&!function(){
var o=function(t){
var o=t.node,n=t.data;
return function(){
var t=document.createElement("div");
t.innerHTML=i.tmpl(e,{
data:n
},!0).replace(/>\s*</g,"><").replace(/^\s+/,"").replace(/\s+$/,"");
var a=t.firstChild;
o.parentNode.insertBefore(a,o.nextSibling);
var r=o.parentNode.querySelector('[data-preloadingid="'+n.id+'"]');
r&&r.parentNode.removeChild(r),g({
dom:a,
poiInfo:n
}),c.poiDom.push(a),f();
};
}(t),n=function(){
this.onload=null,this.onerror=null,o();
},a=new Image;
a.onload=n,a.onerror=n,a.src=t.data.img;
}();
},v=function(){
for(var t=document.querySelectorAll(c.tagName),e=0,n=t.length;n>e;e++){
var i=t[e],a={
id:decodeURIComponent(i.getAttribute("data-id")||""),
name:decodeURIComponent(i.getAttribute("data-name")||""),
address:decodeURIComponent(i.getAttribute("data-address")||""),
img:decodeURIComponent(i.getAttribute("data-img")||""),
longitude:decodeURIComponent(i.getAttribute("data-longitude")||""),
latitude:decodeURIComponent(i.getAttribute("data-latitude")||""),
type:decodeURIComponent(i.getAttribute("data-type")||"")
};
b({
data:a,
node:i
});
}
for(var r=document.getElementsByClassName("js_poi_entry"),d=0;d<r.length;d++)!function(t){
var e=r[t];
c.poiDom.push(e),o.on(e,"tap",function(t){
t.stopPropagation(),t.preventDefault();
var o={
id:decodeURIComponent(e.getAttribute("data-id")||""),
name:decodeURIComponent(e.getAttribute("data-name")||""),
address:decodeURIComponent(e.getAttribute("data-address")||""),
img:decodeURIComponent(e.getAttribute("data-img")||""),
longitude:decodeURIComponent(e.getAttribute("data-longitude")||""),
latitude:decodeURIComponent(e.getAttribute("data-latitude")||""),
type:decodeURIComponent(e.getAttribute("data-type")||"")
};
return o.longitude&&o.latitude&&o.name&&o.address&&(s.report(19937,_extends({},c.commonReportData,{
type:1,
actiontype:2
})),m.setSum(110809,57,1),l(o)),!1;
},!0),o.on(e,"click",function(t){
t.preventDefault(),t.stopPropagation();
},!0);
}(d);
f();
};
v();
});var _extends=Object.assign||function(e){
for(var o=1;o<arguments.length;o++){
var t=arguments[o];
for(var n in t)Object.prototype.hasOwnProperty.call(t,n)&&(e[n]=t[n]);
}
return e;
};
define("appmsg/search/search.js",["biz_common/utils/string/html.js","appmsg/search/search_tpl.html.js","biz_common/dom/event.js","biz_wap/jsapi/core.js","biz_common/tmpl.js","common/utils.js","pages/player_tips.js","biz_wap/utils/mmversion.js","common/comm_report.js","biz_wap/utils/jsmonitor_report.js"],function(e){
"use strict";
e("biz_common/utils/string/html.js");
var o=e("appmsg/search/search_tpl.html.js"),t=e("biz_common/dom/event.js"),n=e("biz_wap/jsapi/core.js"),r=e("biz_common/tmpl.js"),i=e("common/utils.js"),s=e("pages/player_tips.js"),a=e("biz_wap/utils/mmversion.js"),m=e("common/comm_report.js"),d=e("biz_wap/utils/jsmonitor_report.js"),c={
tagName:"mpsearch",
isWechat:(a.isAndroid||a.isIOS)&&a.isWechat&&!a.isWxwork,
keywords:[],
screen_height:i.getInnerHeight(),
exposeHasReport:0,
commonReportData:{
BizUin:window.biz,
MsgId:1*window.mid,
ItemIdx:1*window.idx,
SearchKeyWord:"",
SessionId:window.sessionid,
EnterId:1*window.enterid,
Scene:1*window.source,
SubScene:1*window.subscene
}
},p=function(){
return document.documentElement.scrollTop||document.body.scrollTop;
},l=function(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0];
t.on(e.dom,"click",function(){
var e=c.keywords.map(function(e){
return e.label;
}).join(";");
if(m.report(19453,_extends({},c.commonReportData,{
SearchKeyWord:e,
EventType:2
})),d.setSum(110809,47,1),c.isWechat){
if(a.isIOS&&a.ltVersion("7.0.12")||a.isAndroid&&a.ltVersion("7.0.12"))return void new s({
msg:"当前微信版本不支持展示该内容，请升级至最新版本。"
});
for(var o=[],t=0;t<c.keywords.length;t++)o.push({
hotword:c.keywords[t].label,
id:t,
optype:1
});
n.invoke("openWXSearchPage",{
query:"",
thirdExtParam:JSON.stringify({
data:[{
items:o,
title:window.nickname+"推荐搜索",
type:4
}],
from:"mpWidget",
bizUserName:window.user_name,
bizNickName:window.nickname,
id:"mpWidget_"+c.commonReportData.BizUin+":"+c.commonReportData.MsgId+":"+c.commonReportData.ItemIdx
})
},function(e){
-1!==e.err_msg.indexOf("ok")?d.setSum(110809,48,1):d.setSum(110809,49,1);
});
}else new s({
msg:"请使用移动端微信打开。"
});
});
var o=function(){
if(!c.exposeHasReport){
c.exposeHasReport=1;
var o=p();
if(e.dom.clientHeight+e.dom.offsetTop>=o+e.dom.clientHeight/2&&e.dom.clientHeight+e.dom.offsetTop<=o+e.dom.clientHeight/2+c.screen_height){
var t=c.keywords.map(function(e){
return e.label;
}).join(";");
m.report(19453,_extends({},c.commonReportData,{
SearchKeyWord:t,
EventType:1
})),d.setSum(110809,46,1);
}
}
};
t.on(window,"scroll",o),o();
},u=function(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0];
if(e.node&&e.data&&e.data.keywords){
var t=function(e){
var t=e.node,n=e.data;
return function(){
var e=document.createElement("div");
e.innerHTML=r.tmpl(o,{
data:n
},!0).replace(/>\s*</g,"><").replace(/^\s+/,"").replace(/\s+$/,"");
var i=e.firstChild;
t.parentNode.insertBefore(i,t.nextSibling);
var s=t.parentNode.querySelector('[data-preloadingid="mpsearch"]');
s&&s.parentNode.removeChild(s),l({
dom:i,
keywords:n.keywords
});
};
}(e);
t();
}
},w=function(){
var e=document.querySelectorAll(c.tagName);
if(!(e.length<=0))for(var o=0,t=e.length;t>o;o++){
var n=e[o],r=[];
try{
r=JSON.parse(window.decodeURIComponent(n.getAttribute("data-keywords")));
}catch(i){
d.setSum(110809,50,1);
}
if(r.length){
var s={
nickname:window.nickname,
avatar:window.round_head_img,
keywords:r
};
c.keywords=r,u({
data:s,
node:n
});
}
}
};
w();
});define("redpackage/redpacketcover.js",["biz_common/utils/string/html.js","redpackage/tpl/card_tpl.html.js","biz_common/dom/event.js","biz_wap/jsapi/core.js","biz_common/tmpl.js","common/utils.js","common/comm_report.js","pages/player_tips.js","biz_common/utils/url/parse.js","biz_wap/utils/mmversion.js","biz_wap/utils/ajax.js"],function(e){
"use strict";
e("biz_common/utils/string/html.js");
var t=e("redpackage/tpl/card_tpl.html.js"),a=e("biz_common/dom/event.js"),r=e("biz_wap/jsapi/core.js"),i=e("biz_common/tmpl.js"),o=e("common/utils.js"),n=e("common/comm_report.js"),d=e("pages/player_tips.js"),s=e("biz_common/utils/url/parse.js"),c=e("biz_wap/utils/mmversion.js"),u=e("biz_wap/utils/ajax.js"),p={
tagName:"redpacketcover",
isWechat:c.isWechat,
domMap:{},
dataMap:{},
startTime:window.page_begintime||0,
screen_height:o.getInnerHeight(),
screen_num:0,
pvData:[],
request_id:encodeURIComponent(window.biz+";"+window.mid+";"+window.idx+";"+window.page_begintime||0),
hasBindVisibility:!1,
hasBindScroll:!1,
needReportNum:0,
reportedNum:0
},m=function(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0],t=window.pageYOffset||document.documentElement.scrollTop,a=(window.logs.read_height||t)+p.screen_height,r={
BizUin:window.biz,
MsgId:1*window.mid,
Idx:1*window.idx,
CoverUri:e.coverUri,
Scene:1*window.source,
Subscene:1*window.subscene,
CoverStatus:1*e.coverStatus,
EventType:1*e.eventType,
EventScreenNum:Math.ceil(a/p.screen_height)||1,
ScreenNum:p.screen_num,
StartTimeMs:p.startTime
};
n.report(19119,r);
},l=function(){
for(var e=window.pageYOffset||document.documentElement.scrollTop,t=e+p.screen_height,r=0;r<p.pvData.length;r++){
var i=p.pvData[r];
t>=i.start&&t<=i.end&&(p.reportedNum++,p.dataMap&&p.dataMap[i.coverUri]&&(p.dataMap[i.coverUri].reported=!0),
m({
eventType:2,
coverUri:i.coverUri,
coverStatus:p.dataMap[i.coverUri].status
}),p.pvData.splice(r,1),r--);
}
p.reportedNum>=p.needReportNum&&(a.off(window,"scroll",l),p.pvData=[],l=null);
},v=function(){
p.pvData.length>0&&(!p.hasBindScroll&&l&&(p.hasBindScroll=!0,a.on(window,"scroll",l)),
l());
},_=function(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0];
if(p.isWechat){
p.scroll_height=document.body.scrollHeight||document.body.offsetHeight,p.screen_num=Math.ceil(p.scroll_height/p.screen_height);
var t=e.node;
if(p.dataMap[e.coveruri]&&1*p.dataMap[e.coveruri].status!==-1&&!p.dataMap[e.coveruri].reported){
var a=t.getBoundingClientRect();
p.pvData.push({
start:a.top+a.height/2,
end:a.top+a.height/2+p.screen_height,
coverUri:e.coveruri
});
}
v();
}
},g=null,h=function(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0];
p.dataMap[e.coveruri]&&a.on(e.dom,"click",function(){
window.is_temp_url?new d({
msg:"预览时不支持领取红包封面"
}):p.isWechat?!function(){
var t=e.dom.getAttribute("data-coveruri")||"",a=t&&p.dataMap[t]?p.dataMap[t].redirect_url:"";
a&&(m({
eventType:1,
coverUri:t,
coverStatus:p.dataMap[t].status
}),r.invoke("openUrlWithExtraWebview",{
url:a,
openType:1
},function(e){
-1===e.err_msg.indexOf("ok")&&(location.href=a);
}));
}():new d({
msg:"请在微信客户端打开"
});
}),!p.hasBindVisibility&&p.isWechat&&(p.hasBindVisibility=!0,o.listenStateChange({
cb:function(e){
("onResume"===e.state_change||"onResume"===e.state)&&u({
type:"GET",
dataType:"json",
url:"/mp/wapredpacketcover?action=get_red_packet_cover_data&__biz="+window.biz+"&mid="+window.mid+"&idx="+window.idx+"&sn="+window.sn+"&send_time="+window.send_time,
timeout:1e4,
success:function(e){
if(e&&e.base_resp&&1*e.base_resp.ret===0&&e.red_packet_cover_data&&e.red_packet_cover_data.cover_uri_data&&e.red_packet_cover_data.cover_uri_data.length>0)for(var t=e.red_packet_cover_data.cover_uri_data,a=0,r=t.length;r>a;a++){
var i=t[a],o=p.domMap[i.cover_uri],n=p.dataMap[i.cover_uri];
if(n&&o){
var d=1*n.status,s=1*i.status;
-1!==s&&d!==s&&(n.status=s,g({
data:n,
node:o,
isUpdate:!0
}));
}
}
}
});
}
}));
};
g=function(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0];
e.node&&e.data&&e.data.cover_uri&&(e.isUpdate?e.node.innerHTML=i.tmpl(t,{
data:e.data,
isUpdate:!0
},!1).replace(/>\s*</g,"><").replace(/^\s+/,"").replace(/\s+$/,""):e.data.receive_image&&!function(){
var a=function(e){
var a=e.node,r=e.data;
return function(){
var e=document.createElement("div");
e.innerHTML=i.tmpl(t,{
data:r,
isUpdate:!1
},!1).replace(/>\s*</g,"><").replace(/^\s+/,"").replace(/\s+$/,"");
var o=e.firstChild;
a.parentNode.insertBefore(o,a.nextSibling);
var n=a.parentNode.querySelector('[data-preloadingid="'+r.cover_uri+'"]');
n&&n.parentNode.removeChild(n),p.domMap[r.cover_uri]=o,h({
dom:o,
coveruri:r.cover_uri
}),_({
coveruri:r.cover_uri,
node:o
});
};
}(e),r=function(){
this.onload=null,this.onerror=null,a();
},o=new Image;
o.onload=r,o.onerror=r,o.src=e.data.receive_image;
}());
};
var w=function(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0];
if(e.list&&0!==e.list.length){
for(var t=0,a=e.list.length;a>t;t++){
var r=e.list[t];
p.dataMap[r.cover_uri]=r;
}
var i=document.querySelectorAll(p.tagName);
e.list.length!==i.length&&window.__addIdKeyReport&&window.__addIdKeyReport("27613","51",1),
p.needReportNum=i.length;
for(var t=0,a=i.length;a>t;t++){
var r=i[t],o=r.getAttribute("data-coveruri")||"",n=decodeURIComponent(o),d=p.dataMap[n];
if(d&&1*d.status!==-1){
if(d.redirect_url){
var c=d.redirect_url.html(!1);
c=s.addParam(c,"request_id",p.request_id,!0);
var u=s.parseUrl(c);
u.hash?-1===u.hash.indexOf("wechat_redirect")&&(c+="&wechat_redirect"):c+="#wechat_redirect",
d.redirect_url=c;
}
g({
data:d,
node:r,
isUpdate:!1
});
}
}
}
},f=function(){
var e=document.querySelectorAll(p.tagName);
if(!window.__appmsgCgiData||1*window.__appmsgCgiData.has_red_packet_cover!==1)return void(e.length>0&&window.__addIdKeyReport&&window.__addIdKeyReport("27613","51",1));
if(!p.isWechat)for(var t=0,a=e.length;a>t;t++){
var r=e[t],i=r.getAttribute("data-coveruri")||"",o=decodeURIComponent(i),n=decodeURIComponent(r.getAttribute("data-receiveimg")||"");
if(o&&n&&/^http(s)?:\/\/mmcomm\.qpic\.cn([\/?].*)*$/i.test(n)){
var d={
cover_uri:o,
status:0,
name:"",
redirect_url:"",
receive_image:n
};
p.dataMap[o]=d,g({
data:d,
node:r,
isUpdate:!1
});
}
}
};
return f(),{
render:w
};
});define("appmsg/voice.js",["biz_common/utils/string/html.js","pages/voice_tpl.html.js","appmsg/log.js","pages/voice_component.js"],function(e){
"use strict";
function i(){
var e=c("js_content");
return e?(p._oElements=e.getElementsByTagName("mpvoice")||[],p._oElements.length<=0?!1:!0):!1;
}
function o(){
p.musicLen=p._oElements.length;
}
function n(e){
for(var i=0,o=0;o<p.musicLen;o++){
var n=p._oElements[o],a={},c=n.getAttribute("voice_encode_fileid")||"";
try{
c=decodeURIComponent(c);
}catch(d){}
a.voiceid=m.encodeStr(c),a.voiceid=a.voiceid.replace(/&#61;/g,"=").replace(/^\s/,"").replace(/\s$/,""),
a.isaac=1*n.getAttribute("isaac2")||0,a.src=p.srcRoot.replace("#meidaid#",a.voiceid),
1===a.isaac&&(a.jsapi2Src=a.src+"&voice_type=1"),a.voiceid&&"undefined"!=a.voiceid&&(a.albumLink="",
e&&e.length>0&&e.forEach(function(e){
return e.voice_id===c?(e.appmsgalbuminfo&&(a.albumTitle=e.appmsgalbuminfo.title,
a.albumLink=e.appmsgalbuminfo.link.replace("#wechat_redirect","")+"#wechat_redirect",
a.albumNum=e.appmsgalbuminfo.tag_content_num||0,a.albumid=e.appmsgalbuminfo.album_id||0),
!1):void 0;
}),t(n,a,i),"undefined"!=typeof voiceid&&c&&voiceid&&c===voiceid&&!function(){
var e=n.offsetTop+122-40;
setTimeout(function(){
window.scrollTo(0,e);
},0);
}(),i++);
}
}
function t(e,i,o){
i.duration=parseInt((1*e.getAttribute("play_length")||0)/1e3,10),i.duration_str=m.formatTime(i.duration),
i.posIndex=o;
var n=e.getAttribute("name")||"";
try{
n=decodeURIComponent(n);
}catch(t){}
i.title=m.encodeStr(n).replace(/^\s/,"").replace(/\s$/,""),i.fileSize=1*e.getAttribute("high_size")||0,
i.nickname=window.nickname,m.renderPlayer(r,i,e);
var c=i.voiceid+"_"+i.posIndex,d=e.parentNode.querySelector('[data-preloadingid="'+c+'"]');
d&&d.parentNode.removeChild(d),a(i),p.musicList[i.voiceid+"_"+i.posIndex]=i;
}
function a(e){
var i=e.voiceid+"_"+e.posIndex,o="";
if(window.voice_in_appmsg&&window.voice_in_appmsg[e.voiceid]){
var n=window.voice_in_appmsg[e.voiceid],t=window.biz||"",a=window.mid||"",d=window.idx||"";
n.bizuin&&n.appmsgid&&n.idx&&(t=n.bizuin,a=n.appmsgid,d=n.idx);
var r=window.location.protocol||"https:";
o=r+"//mp.weixin.qq.com/mp/audio?_wxindex_=#_wxindex_#&scene=104&__biz=#biz#&mid=#mid#&idx=#idx#&voice_id=#voice_id#&sn=#sn##wechat_redirect".replace("#_wxindex_#",e.posIndex).replace("#biz#",t).replace("#mid#",a).replace("#idx#",d).replace("#voice_id#",e.voiceid).replace("#sn#",n.sn||"");
}
s("[Voice] init"+o);
var p=m.decodeStr(e.title);
e.player=m.init({
wxIndex:e.posIndex,
type:2,
songId:e.voiceid,
comment_id:"",
src:e.src,
jsapi2Src:e.jsapi2Src,
allowPause:!0,
duration:e.duration,
title:p,
singer:window.nickname?window.nickname+"的语音":"公众号语音",
epname:"来自文章",
coverImgUrl:window.__appmsgCgiData.hd_head_img,
playingCss:"share_audio_playing",
playCssDom:c("voice_main_"+i),
playArea:c("voice_play_"+i),
progress:c("voice_progress_"+i),
fileSize:e.fileSize,
playtimeDom:c("voice_playtime_"+i),
bufferDom:c("voice_buffer_"+i),
playdotDom:c("voice_playdot_"+i),
seekRange:c("voice_seekRange_"+i),
seekContainer:c("voice_main_"+i),
loadingDom:c("voice_loading_"+i),
detailArea:o?c("voice_main_"+i):"",
albumDom:c("voice_album_"+i),
detailUrl:o,
webUrl:o
});
}
function c(e){
return document.getElementById(e);
}
function d(e){
i()&&(o(),n(e));
}
e("biz_common/utils/string/html.js");
var r=e("pages/voice_tpl.html.js"),s=e("appmsg/log.js"),m=e("pages/voice_component.js"),p={
musicList:{},
musicLen:0,
srcRoot:location.protocol+"//res.wx.qq.com/voice/getvoice?mediaid=#meidaid#"
};
return{
init:d
};
});define("appmsg/qqmusic.js",["biz_common/utils/string/html.js","biz_common/utils/url/parse.js","appmsg/log.js","pages/qqmusic_tpl.html.js","pages/voice_component.js","pages/qqmusic_ctrl.js","pages/kugoumusic_ctrl.js"],function(e){
"use strict";
function t(){
var e=u("js_content");
return e?(p._oElements=e.getElementsByTagName("qqmusic")||[],p._oElements.length<=0?!1:!0):!1;
}
function i(){
p.musicLen=p._oElements.length;
}
function s(){
for(var e=0,t=0;t<p.musicLen;t++){
var i=p._oElements[t],s={};
s.musicid=l.encodeStr(i.getAttribute("musicid")||"").replace(/^\s/,"").replace(/\s$/,""),
s.musicid&&"undefined"!=s.musicid&&(r(i,s,e),e++);
}
}
function r(e,t,i){
if(t.media_id=l.encodeStr(e.getAttribute("mid")||"").replace(/^\s/,"").replace(/\s$/,""),
t.musictype=parseInt(e.getAttribute("musictype"))||1,t.musictype>2&&(t.musictype=2),
t.albumid=l.encodeStr(e.getAttribute("albumid")||"").replace(/^\s/,"").replace(/\s$/,""),
t.otherid=l.encodeStr(e.getAttribute("otherid")||"").replace(/^\s/,"").replace(/\s$/,""),
t.jumpurlkey=l.encodeStr(e.getAttribute("jumpurlkey")||"").replace(/^\s/,"").replace(/\s$/,""),
t.duration=parseInt(e.getAttribute("play_length")||0,10),t.posIndex=i,t.albumurl=l.encodeStr(e.getAttribute("albumurl")||"").replace(/^\s/,"").replace(/\s$/,""),
t.audiourl=l.encodeStr(e.getAttribute("audiourl")||"").replace(/^\s/,"").replace(/\s$/,""),
t.singer=l.encodeStr(e.getAttribute("singer")||"").replace(/^\s/,"").replace(/\s$/,""),
!t.singer||"undefined"==t.singer){
var s=e.getAttribute("src")||"",r=decodeURIComponent(a.getQuery("singer",s)||"");
t.singer=l.encodeStr(r).replace(/^\s/,"").replace(/\s$/,""),t.singer&&"undefined"!=t.singer||(t.singer="");
}
t.music_name=l.encodeStr(e.getAttribute("music_name")||"").replace(/^\s/,"").replace(/\s$/,""),
p.adapter[t.musictype]&&"function"==typeof p.adapter[t.musictype].initData&&(t=p.adapter[t.musictype].initData(t,{
scene:0
})),l.renderPlayer(m,t,e);
var u=t.musicid+"_"+t.posIndex,c=e.parentNode.querySelector('[data-preloadingid="'+u+'"]');
c&&c.parentNode.removeChild(c),n(t),p.musicList[t.musicid+"_"+t.posIndex]=t;
}
function n(e){
var t=e.musicid+"_"+e.posIndex;
c("[Music] init "+e.detailUrl);
var i=l.decodeStr(e.music_name);
e.player=l.init({
allowPause:e.allowPause===!0?!0:!1,
wxIndex:e.posIndex,
type:e.type||0,
comment_id:"",
mid:e.media_id,
otherid:e.otherid,
albumid:e.albumid,
songId:e.musicid,
jumpurlkey:e.jumpurlkey,
duration:e.duration,
title:i,
singer:window.nickname?window.nickname+"推荐的歌":"公众号推荐的歌",
epname:"音乐",
coverImgUrl:e.albumurl,
playingCss:"qqmusic_playing",
pauseCss:e.pauseCss||"",
playCssDom:u("qqmusic_main_"+t),
playArea:u("qqmusic_play_"+t),
detailUrl:e.detailUrl||"",
webUrl:e.webUrl||"",
detailArea:u("qqmusic_home_"+t)
});
}
function u(e){
return document.getElementById(e);
}
e("biz_common/utils/string/html.js");
var a=e("biz_common/utils/url/parse.js"),c=e("appmsg/log.js"),m=e("pages/qqmusic_tpl.html.js"),l=e("pages/voice_component.js"),p={
adapter:{
1:e("pages/qqmusic_ctrl.js"),
2:e("pages/kugoumusic_ctrl.js")
},
musicList:{},
musicLen:0
};
return t()?(i(),s(),p.musicList):void 0;
});define("appmsg/iframe.js",["biz_common/utils/string/html.js","pages/video_communicate_adaptor.js","biz_wap/utils/mmversion.js","biz_wap/utils/device.js","biz_wap/utils/ajax.js","common/utils.js","appmsg/finance_communicate.js","biz_wap/utils/jsmonitor_report.js","biz_common/utils/url/parse.js","new_video/ctl.js","pages/version4video.js","biz_common/dom/attr.js","biz_common/dom/event.js"],function(e){
"use strict";
function t(e){
console.info("iframe_onload");
var t=0;
try{
e.contentDocument&&e.contentDocument.body.offsetHeight?t=e.contentDocument.body.offsetHeight:e.Document&&e.Document.body&&e.Document.body.scrollHeight?t=e.Document.body.scrollHeight:e.document&&e.document.body&&e.document.body.scrollHeight&&(t=e.document.body.scrollHeight);
var i=e.parentElement;
if(i&&(e.style.height=t+"px"),/MSIE\s(7|8)/.test(navigator.userAgent)&&e.contentWindow&&e.contentWindow.document){
var o=e.contentWindow.document.getElementsByTagName("html");
o&&o.length&&(o[0].style.overflow="hidden");
}
c&&c.postPageHeightMessage&&c.postPageHeightMessage("updatePageHeight"),console.log("financeUtils done");
}catch(n){}
}
function i(){
for(var e=window.pageYOffset||document.documentElement.scrollTop,t=_.video_top.length,n=e+s.getInnerHeight(),d=0,r=0;t>r;r++){
var c=_.video_top[r];
c.reported?d++:n>=c.start&&n<=c.end&&(c.reported=!0,setTimeout(function(e,t,i){
return function(){
var n=o.getVideoInfo(),d="",r="",s=3;
n[e]&&(n[e].hit_bizuin&&(d=n[e].hit_bizuin),n[e].hit_vid&&(r=n[e].hit_vid),n[e].ori_status&&(s=n[e].ori_status)),
p.report({
step:1,
hit_vid:r,
hit_bizuin:d,
ori_status:s,
vid:e,
screen_num:Math.ceil(t/i),
screen_height:i
});
};
}(c.vid,n,s.getInnerHeight()),1e4));
}
d==t&&(w.off(window,"scroll",i),_.video_top=_.video_iframe=i=null);
}
e("biz_common/utils/string/html.js");
{
var o=e("pages/video_communicate_adaptor.js"),n=e("biz_wap/utils/mmversion.js"),d=e("biz_wap/utils/device.js"),r=e("biz_wap/utils/ajax.js"),s=e("common/utils.js"),c=e("appmsg/finance_communicate.js"),a=e("biz_wap/utils/jsmonitor_report.js"),m=e("biz_common/utils/url/parse.js"),p=e("new_video/ctl.js"),_={
txVideoReg:/^http(s)*\:\/\/v\.qq\.com\/iframe\/(preview|player)\.html\?/,
mpVideoReg:/^http(s)*\:\/\/mp\.weixin\.qq\.com\/mp\/readtemplate\?t=pages\/video_player_tmpl/,
video_iframe:[],
video_top:[]
},l=e("pages/version4video.js"),u=e("biz_common/dom/attr.js"),w=(u.setProperty,e("biz_common/dom/event.js")),f=document.getElementsByTagName("iframe"),g=[];
/MicroMessenger/.test(navigator.userAgent);
}
window.reportVid=[];
for(var v=Math.ceil(1e4*Math.random()),h=0,x=f.length;x>h;++h)!function(e){
var i=e.getAttribute("data-src")||"",o=e.className||"",s=e.getAttribute("src")||i;
if(!i||"#"==i){
var c=e.getAttribute("data-display-src");
if(c&&(0==c.indexOf("/cgi-bin/readtemplate?t=vote/vote-new_tmpl")||0==c.indexOf("https://mp.weixin.qq.com/cgi-bin/readtemplate?t=vote/vote-new_tmpl"))){
c=c.replace(/&amp;/g,"&");
for(var p=c.split("&"),u=["/mp/newappmsgvote?action=show"],w=0;w<p.length;w++)(0==p[w].indexOf("__biz=")||0==p[w].indexOf("supervoteid="))&&u.push(p[w]);
u.length>1&&(i=u.join("&")+"#wechat_redirect");
}
}
if(s&&(_.txVideoReg.test(s)||_.mpVideoReg.test(s))){
if(l.isShowMpVideo()||_.mpVideoReg.test(s)){
var f=m.getQuery("vid",i);
if(!f)return;
var h=e.getAttribute("data-vw"),x=e.getAttribute("data-vh"),b=document.domain;
"qq.com"==b&&((new Image).src="https://badjs.weixinbridge.com/badjs?id=139&level=4&from="+window.encodeURIComponent(window.location.host)+"&msg="+window.encodeURIComponent(window.location.href),
a.setLogs({
id:27302,
key:100,
value:1,
lc:1,
log0:"[beforeD]"+window.encodeURIComponent(window.location.href)
})),window.reportVid.push(f),_.video_iframe.push({
dom:e,
vid:f
}),s=["/mp/videoplayer?video_h=",x,"&video_w=",h,"&scene=",window.source,"&random_num=",v,"&article_title=",encodeURIComponent(window.msg_title.htmlDecode()),"&source=4&vid=",f,"&mid=",appmsgid,"&idx=",itemidx||idx,"&__biz=",biz,"&nodetailbar=",window.is_temp_url?1:0,"&uin=",uin,"&key=",key,"&pass_ticket=",pass_ticket,"&version=",version,"&devicetype=",window.devicetype||"","&wxtoken=",window.wxtoken||"","&sessionid=",window.sessionid||"","&preview=",window.is_temp_url?1:0,"&is_in_pay_subscribe=",window.isPaySubscribe,"&nickname="+window.nickname,"&roundHeadImg="+window.round_head_img,"&enterid="+window.enterid,"&subscene="+window.subscene].join(""),
uin||window.__addIdKeyReport&&window.__addIdKeyReport("28307",21),window.__addIdKeyReport&&window.__addIdKeyReport("28307",11),
setTimeout(function(e,t){
if(t.setAttribute("marginWidth",0),t.setAttribute("marginHeight",0),t.style.top="0",
window.__second_open__)if(n.isIOS){
var i,o,s;
!function(){
var n=function(e,t,i,o){
i&&o&&(e.contentWindow.__auto_play__=!!e.getAttribute("__sec_open_auto_play__"),
e.contentWindow.is_login=t.is_login,e.contentWindow.user_uin=t.user_uin,e.contentWindow.cgiData.ckey=t.ckey,
e.contentWindow.cgiData.ckey_ad=t.ckey_ad,e.contentWindow.seajs.use("pages/video_appmsg.js"));
},c=function(){
d.os.getNumVersion()<14?t.setAttribute("src",e):t.contentWindow.location.replace(e);
};
window.__videohook__=1,i=!1,o=!1,s={},t.onload=function(){
t.contentWindow&&t.contentWindow.cgiData?i=!0:(i=!1,c()),n(t,s,i,o);
},c(),r({
url:e,
type:"GET",
f:"json",
success:function(d){
o=!0;
try{
s=JSON.parse(d),n(t,s,i,o);
}catch(r){
n(t,s,i,o);
}
window.resp=d,t.setAttribute("data-realsrc",e),t.contentWindow.__iframe_src__=e;
}
});
}();
}else r({
url:e,
type:"GET",
f:"html",
success:function(i){
t.setAttribute("data-realsrc",e),t.contentDocument.open("text/html","replace"),t.contentDocument.write(i),
t.contentDocument.close(),t.contentWindow.__iframe_src__=e,t.contentWindow.history.replaceState(null,null,e);
}
});else t.setAttribute("src",e);
},0,s,e);
}
}else if(i&&(i.indexOf("newappmsgvote")>-1&&(o.indexOf("js_editor_vote_card")>=0||o.indexOf("vote_iframe")>=0)||0==i.indexOf("http://mp.weixin.qq.com/bizmall/appmsgcard")&&(o.indexOf("card_iframe")>=0||o.indexOf("js_editor_card")>=0)||i.indexOf("appmsgvote")>-1||i.indexOf("mp.weixin.qq.com/mp/getcdnvideourl")>-1)){
if(window.is_transfer_msg&&!window.reprint_ticket&&i.indexOf(window.biz)<0)return void g.push(e);
if(window.__second_open__||(i=i.replace(/^http:/,location.protocol)),o.indexOf("card_iframe")>=0||o.indexOf("js_editor_card")>=0){
-1===o.indexOf("card_iframe")&&(e.className+=" card_iframe"),-1===o.indexOf("res_iframe")&&(e.className+=" res_iframe");
var y=i.replace("#wechat_redirect",["&pass_ticket=",pass_ticket,"&scene=",source,"&msgid=",appmsgid,"&msgidx=",itemidx||idx,"&version=",version,"&devicetype=",window.devicetype||"","&child_biz=",biz,"&wxtoken=",window.wxtoken||""].join(""));
reprint_ticket&&(y+=["&mid=",mid,"&idx=",idx,"&reprint_ticket=",reprint_ticket,"&source_mid=",source_mid,"&source_idx=",source_idx].join("")),
window.__second_open__?r({
url:y,
type:"GET",
f:"html",
success:function(o){
e.setAttribute("src",y),e.contentWindow.document.open("text/html","replace"),e.contentWindow.document.write(o),
e.contentWindow.document.close(),e.contentWindow.history.replaceState(null,null,y),
-1==i.indexOf("mp.weixin.qq.com/mp/getcdnvideourl")&&(e.onload=function(){
t(e);
});
}
}):(e.setAttribute("src",y),-1==i.indexOf("mp.weixin.qq.com/mp/getcdnvideourl")&&(e.onload=function(){
t(e);
}));
}else{
var j=i.indexOf("#wechat_redirect")>-1,k=["&uin=",uin,"&key=",key,"&pass_ticket=",pass_ticket,"&wxtoken=",window.wxtoken||""].join("");
reprint_ticket?k+=["&mid=",mid,"&idx=",idx,"&reprint_ticket=",reprint_ticket,"&source_mid=",source_mid,"&source_idx=",source_idx,"&appmsg_token=",appmsg_token].join(""):(o.indexOf("vote_iframe")>=0||o.indexOf("js_editor_vote_card")>=0)&&(k+=["&mid=",mid,"&idx=",idx,"&appmsg_token=",appmsg_token].join(""),
-1===o.indexOf("vote_iframe")&&(e.className+=" vote_iframe"));
var y=j?i.replace("#wechat_redirect",k):i+k;
window.__second_open__?r({
url:y,
type:"GET",
f:"html",
success:function(o){
e.contentWindow.Ajax=r,e.setAttribute("src",y),e.contentWindow.document.open("text/html","replace"),
e.contentWindow.document.write(o),e.contentWindow.document.close(),e.contentWindow.history.replaceState(null,null,y),
-1==i.indexOf("mp.weixin.qq.com/mp/getcdnvideourl")&&(e.onload=function(){
t(e);
});
}
}):(e.setAttribute("src",y),-1==i.indexOf("mp.weixin.qq.com/mp/getcdnvideourl")&&(e.onload=function(){
t(e);
}));
}
e.appmsg_idx=w;
}
if(i&&i.indexOf("mp.weixin.qq.com/mp/getcdnvideourl")>-1&&h>0){
var O=h,z=3*O/4;
e.width=O,e.height=z,e.style.setProperty&&(e.style.setProperty("width",O+"px","important"),
e.style.setProperty("height",z+"px","important"));
}
}(f[h]);
for(var b=0;b<g.length;b++){
var y=g[b];
y.parentNode.removeChild(y);
}
if(window.iframe_reload=function(){
for(var e=0,i=f.length;i>e;++e){
var o=f[e],n=o.getAttribute("src");
n&&(n.indexOf("newappmsgvote")>-1||n.indexOf("appmsgvote")>-1)&&t(o);
}
},"getElementsByClassName"in document)for(var j,k=document.getElementsByClassName("video_iframe"),h=0;j=k.item(h++);)j.setAttribute("scrolling","no"),
j.style.overflow="hidden";
_.video_iframe.length>0&&setTimeout(function(){
for(var e=_.video_iframe,t=document.getElementById("js_article"),o=0,n=e.length;n>o;o++){
var d=e[o];
if(!d||!d.dom)return;
for(var r=d.dom,c=r.offsetHeight,a=0;r&&t!==r;)a+=r.offsetTop,r=r.offsetParent;
_.video_top.push({
start:a+c/2,
end:a+c/2+s.getInnerHeight(),
reported:!1,
vid:d.vid
});
}
i(),w.on(window,"scroll",i);
});
});define("appmsg/page_pos.js",["biz_common/utils/string/html.js","biz_common/dom/event.js","biz_wap/utils/ajax.js","biz_common/utils/cookie.js","biz_common/utils/http.js","appmsg/cdn_img_lib.js","biz_wap/utils/storage.js","biz_wap/utils/hand_up_state.js","biz_wap/utils/mmversion.js","biz_wap/jsapi/core.js","biz_wap/jsapi/leaveReport.js","biz_wap/utils/wapsdk.js","common/utils.js","appmsg/log.js","biz_common/utils/url/parse.js","biz_wap/utils/jsmonitor_report.js"],function(e){
"use strict";
function o(e){
window.logs||(window.logs={}),T.js_content=e.js_content||document.getElementById("js_content");
var o=e.js_toobar3||document.getElementById("js_toobar3");
T.pageEndTop=o?o.offsetTop:0,T.imgs=T.js_content?T.js_content.getElementsByTagName("img")||[]:[],
T.media=e.media||document.getElementById("media"),T.title=e.title||(window.msg_title||"").htmlDecode(),
T.video_cnt=e.video_cnt||window.logs.video_cnt||0,T.js_cmt_area=e.js_cmt_area||document.getElementById("js_cmt_area"),
T.item_show_type=e.item_show_type||window.item_show_type||0,z=document.getElementsByTagName("html"),
z&&1==!!z.length&&l&&(z=z[0].innerHTML,x.content_length=l.htmlSize),window.logs.pageinfo=x,
function(){
if(window.localStorage&&!localStorage.getItem("clear_page_pos")){
for(var e=localStorage.length-1;e>=0;){
var o=localStorage.key(e);
o.match(/^\d+$/)?localStorage.removeItem(o):o.match(/^adinfo_/)&&localStorage.removeItem(o),
e--;
}
localStorage.setItem("clear_page_pos","true");
}
}(),window.localStorage&&(m.on(window,"load",function(){
B=1*S.get(H);
var o=""!==y.getQuery("imageIndex");
if(!window.__second_open__){
var t=location.href.indexOf("scrolltodown")>-1;
t&&"scrollRestoration"in history&&(history.scrollRestoration="manual"),t||"undefined"!=typeof voiceid&&voiceid||(!e.disableScroll&&!o&&window.scrollTo(0,B),
f.saveSpeeds({
uin:uin,
pid:"https:"==E?462:417,
speeds:{
sid:36,
time:Math.ceil(B/v.getInnerHeight())
}
}),f.send());
}
if(window.__wxjs_is_wkwebview||window.__second_open__){
if(q)return;
var i=A.getData(),n=localStorage.getItem("hand_up_id");
for(var p in i)p!=n&&i[p]&&(s(i[p].val),j.setSum(28307,59,1),A.remove(p));
window.setInterval(function(){
var e=a();
A.set(M,e,+new Date+864e7);
},1e3);
}
var m=I.getData("spad");
m&&m.spad&&d(m.spad.val),e.hasSpAd&&window.setInterval(function(){
r();
var e=_();
I.set("spad",e,+new Date+864e7);
},1e3),window.setTimeout(function(){
w({
url:"/mp/appmsgreport?action=page_time_5s&__biz="+biz,
type:"POST",
mayAbort:!0,
data:a(),
async:!0,
timeout:2e3
});
},5e3);
}),m.on(window,"unload",function(){
if(b("[Appmsg leaveReport in page_pos 3]"),console.log("[Appmsg leaveReport in page_pos 3]"),
!window.__second_open__&&(b("[Appmsg leaveReport in page_pos 4]"),console.log("[Appmsg leaveReport in page_pos 4]"),
!window.__jsapi_report_has_done__)){
b("[Appmsg leaveReport in page_pos 5]"),console.log("[Appmsg leaveReport in page_pos 5]"),
localStorage.setItem("hand_up_id",""),window.__ajaxtest="2";
var e=a();
s(e),window.__unload_has_done__=!0;
}
}),window.logs.read_height=0,m.on(window,"scroll",function(){
var e=window.pageYOffset||document.documentElement.scrollTop;
window.logs.read_height=Math.max(window.logs.read_height,e),clearTimeout(N),N=setTimeout(function(){
B=window.pageYOffset,S.set(H,B,+new Date+864e5);
},500);
}),m.on(document,"touchmove",function(){
var e=window.pageYOffset||document.documentElement.scrollTop;
window.logs.read_height=Math.max(window.logs.read_height,e),clearTimeout(N),N=setTimeout(function(){
B=window.pageYOffset,S.set(H,B,+new Date+864e5);
},500);
})),h.addReport(function(){
if(b("[Appmsg leaveReport in page_pos 1]"),console.log("[Appmsg leaveReport in page_pos 1]"),
!window.__unload_has_done__){
b("[Appmsg leaveReport in page_pos 2]"),console.log("[Appmsg leaveReport in page_pos 2]"),
D=!0,A.remove(M);
var e=a(),o=[];
for(var t in e)e.hasOwnProperty(t)&&o.push(t+"="+encodeURIComponent(e[t]));
var i={
reportUrl:"https://mp.weixin.qq.com/mp/appmsgreport?action=page_time&__biz="+biz,
reportData:o.join("&"),
method:"POST"
};
return window.__jsapi_report_has_done__=!0,b("[Appmsg leaveReport length]: "+JSON.stringify(i).length),
console.log("[Appmsg leaveReport length]: "+JSON.stringify(i).length),i;
}
}),m.on(document,"visibilitychange",function(){
g.isHidden()?localStorage.setItem("hand_up_id",M):localStorage.setItem("hand_up_id","");
}),p();
}
function t(e,o){
if(e&&!(e.length<=0))for(var t,i,n,a=/http(s)?\:\/\/([^\/\?]*)(\?|\/)?/,s=0,r=e.length;r>s;++s)t=e[s],
t&&(i=t.getAttribute(o),i&&(n=i.match(a),n&&n[2]&&(O[n[2]]=!0)));
}
function i(e){
for(var o=0,t=k.length;t>o;++o)if(k[o]==e)return!0;
return!1;
}
function n(){
O={},t(document.getElementsByTagName("a"),"href"),t(document.getElementsByTagName("link"),"href"),
t(document.getElementsByTagName("iframe"),"src"),t(document.getElementsByTagName("script"),"src"),
t(document.getElementsByTagName("img"),"src");
var e=[];
for(var o in O)O.hasOwnProperty(o)&&(window.networkType&&"wifi"==window.networkType&&!R&&i(o)&&(R=!0),
e.push(o));
return O={},e.join(",");
}
function a(){
{
var e,o=window.pageYOffset||document.documentElement.scrollTop,t=T.js_content,i=v.getInnerHeight(),a=T.screen_width,s=T.scroll_height,r=Math.ceil(s/i),_=Math.ceil((t.scrollHeight||t.offsetHeight)/i),d=(window.logs.read_height||o)+i,p=T.pageEndTop,m=T.imgs,w=Math.ceil(d/i)||1,l=T.media,c=50,u=0,h=0,f=0,b=0,y=d+c>p?1:0;
t.offsetTop+t.scrollHeight;
}
w>r&&(w=r);
var j=function(o){
if(o)for(var t=0,i=o.length;i>t;++t){
var n=o[t];
if(n){
u++;
var a=n.getAttribute("src"),s=n.getAttribute("data-type");
a&&0==a.indexOf("http")&&(h++,a.isCDN()&&(f++,-1!=a.indexOf("tp=webp")&&b++),s&&(e["img_"+s+"_cnt"]=e["img_"+s+"_cnt"]||0,
e["img_"+s+"_cnt"]++));
}
}
e.download_cdn_webp_img_cnt=b||0,e.download_img_cnt=h||0,e.download_cdn_img_cnt=f||0,
e.img_cnt=u||0;
},S=window.appmsgstat||{},A=window.logs.img||{},I=window.logs.pagetime||{},O=A.load||{},E=A.read||{},k=[],D=[],N=0,B=0,H=0;
for(var P in E)P&&0==P.indexOf("http")&&E.hasOwnProperty(P)&&D.push(P);
for(var P in O)P&&0==P.indexOf("http")&&O.hasOwnProperty(P)&&k.push(P);
for(var M=0,q=k.length;q>M;++M){
var G=k[M];
G&&G.isCDN()&&(-1!=G.indexOf("/0")&&N++,-1!=G.indexOf("/640")&&B++,-1!=G.indexOf("/300")&&H++);
}
var e={
report_bizuin:biz,
title:T.title,
mid:mid,
idx:idx,
subscene:window.subscene||1e4,
sessionid:window.sessionid||0,
read_cnt:S.read_num||0,
old_like_cnt:S.old_like_num||0,
like_cnt:S.like_num||0,
screen_width:a,
screen_height:v.getInnerHeight(),
screen_num:_,
idkey:"",
copyright_stat:"",
ori_article_type:"",
video_cnt:T.video_cnt,
read_screen_num:w||0,
is_finished_read:y,
scene:source,
content_len:x.content_length||0,
start_time:page_begintime,
end_time:(new Date).getTime(),
handup_time:g.getHandUpTime(),
total_height:p,
exit_height:d>p?p:d,
img_640_cnt:B,
img_0_cnt:N,
img_300_cnt:H,
wtime:I.onload_time||0,
ftime:I.ftime||0,
ptime:I.ptime||0,
onload_time:I.onload_time||0,
reward_heads_total:window.logs.reward_heads_total||0,
reward_heads_fail:window.logs.reward_heads_fail||0,
outer_pic:window.logs.outer_pic||0,
publish_time:window.ct,
item_show_type:T.item_show_type,
page_req_info:JSON.stringify({
startGetAppmsgExtTime:window.startGetAppmsgExtTime,
startGetAppmsgAdTime:window.startGetAppmsgAdTime,
receiveGetAppmsgExt:window.receiveGetAppmsgExt,
receiveGetAppmsgAd:window.receiveGetAppmsgAd,
jsapiReadyTime:window.jsapiReadyTime,
domCompleteTime:window.domCompleteTime
})
};
if(window.networkType&&"wifi"==window.networkType&&(e.wifi_all_imgs_cnt=k.length,
e.wifi_read_imgs_cnt=D.length),window.logs.webplog&&4==window.logs.webplog.total){
var C=window.logs.webplog;
e.webp_total=1,e.webp_lossy=C.lossy,e.webp_lossless=C.lossless,e.webp_alpha=C.alpha,
e.webp_animation=C.animation;
}
if(e.copyright_stat=window.isCartoonCopyright?"3":window._copyright_stat||"",e.ori_article_type=window._ori_article_type||"",
window.__addIdKeyReport&&window.moon&&(moon.hit_num>0&&moon.hit_num<1e3&&window.__addIdKeyReport(27613,30,moon.hit_num),
moon.mod_num>0&&moon.mod_num<1e3&&window.__addIdKeyReport(27613,31,moon.mod_num)),
window.logs.idkeys){
var Y=window.logs.idkeys,J=[];
for(var K in Y)if(Y.hasOwnProperty(K)){
var U=Y[K];
U.val>0&&J.push(K+"_"+U.val);
}
e.idkey=J.join(";");
}
j(!!l&&l.getElementsByTagName("img")),j(m);
var L=(new Date).getDay(),V=n();
return(R||0!==user_uin&&Math.floor(user_uin/100)%7==L)&&(e.domain_list=V),R&&(e.html_content=z),
window.isSg&&(e.from="sougou"),e.source=window.friend_read_source||"",e.req_id=window.req_id||"",
e.recommend_version=window.friend_read_version||"",e.class_id=window.friend_read_class_id||"",
e.ascene=window.ascene||-1,0==e.scene&&56==e.ascene&&(e.scene=90),e.hotspotjson=JSON.stringify({
hotspotinfolist:window.hotspotInfoList||[]
}),e.is_pay_subscribe=window.isPaySubscribe,e.is_paid=window.isPaid,e.preview_percent=window.previewPercent,
e.is_finished_preview=window.is_finished_preview||0,e.fee=window.paySubscribeInfo?window.paySubscribeInfo.fee:"",
e.pay_cnt=window.paySubscribeInfo?window.paySubscribeInfo.pay_cnt:"",e.worthy_cnt=window.paySubscribeInfo?window.paySubscribeInfo.like_cnt:"",
e.exptype=window.exptype||"",e.expsessionid=window.expsessionid||"",e;
}
function s(e){
D||(D=!0,A.remove(M),e.report_time=parseInt(+new Date/1e3),w({
url:"/mp/appmsgreport?action=page_time&__biz="+biz,
type:"POST",
mayAbort:!0,
data:e,
async:!1,
timeout:2e3
}));
}
function r(){
S.set(H,B,+new Date+72e5);
}
function _(){
return window.__video_report_data;
}
function d(e){
e&&e.play_type&&(I.remove("spad"),e.report_type=1,w({
url:"/mp/ad_video_report?action=video_play_report",
type:"POST",
mayAbort:!0,
data:e,
async:!1,
timeout:2e3
}));
}
function p(){
(new Image).src=location.protocol+"//mp.weixin.qq.com/mp/geticon?__biz="+biz+"&r="+Math.random();
}
e("biz_common/utils/string/html.js");
var m=e("biz_common/dom/event.js"),w=e("biz_wap/utils/ajax.js"),l=(e("biz_common/utils/cookie.js"),
e("biz_common/utils/http.js"));
e("appmsg/cdn_img_lib.js");
var c=e("biz_wap/utils/storage.js"),g=e("biz_wap/utils/hand_up_state.js"),u=e("biz_wap/utils/mmversion.js"),h=(e("biz_wap/jsapi/core.js"),
e("biz_wap/jsapi/leaveReport.js")),f=e("biz_wap/utils/wapsdk.js"),v=e("common/utils.js"),b=e("appmsg/log.js"),y=e("biz_common/utils/url/parse.js"),j=(-1!=navigator.userAgent.indexOf("TBS/"),
e("biz_wap/utils/jsmonitor_report.js"));
window.__unload_has_done__=!1;
var z,T={
js_cmt_area:null,
js_content:null,
screen_height:v.getInnerHeight(),
screen_width:document.documentElement.clientWidth||window.innerWidth,
scroll_height:document.body.scrollHeight||document.body.offsetHeight,
pageEndTop:0,
imgs:[],
media:null,
title:"",
video_cnt:0,
item_show_type:0
},S=new c("page_pos"),A=new c("time_on_page"),I=new c("spad"),x={},O={},E=window.location.protocol,R=!1,k=["wap.zjtoolbar.10086.cn","125.88.113.247","115.239.136.61","134.224.117.240","hm.baidu.com","c.cnzz.com","w.cnzz.com","124.232.136.164","img.100msh.net","10.233.12.76","wifi.witown.com","211.137.132.89","qiao.baidu.com","baike.baidu.com"],D=!1,N=null,B=0,H=[biz,sn,mid,idx].join("_"),P=Math.random(),M=[biz,sn,mid,idx,P].join("_"),q=u.isAndroid&&u.gtVersion("7.0.4",!0)||u.isIOS&&u.gtVersion("7.0.4",!0);
return{
init:o
};
});define("appmsg/product.js",["biz_common/dom/event.js","common/utils.js"],function(e){
"use strict";
function t(){
for(var e=window.pageYOffset||document.documentElement.scrollTop,t=0;t<i.length;++t){
var o=i[t];
if(!o.isReport){
var n=o.offsetTop;
n>=e&&e+r.getInnerHeight()>=n&&(o.isReport=!0,(new Image).src="/mp/appmsgreport?action=appmsg_recom&type=1&__biz="+biz+"&ascene="+(window.ascene||-1)+"&mid="+mid+"&idx="+idx+"&sn="+sn+"&product_id="+o.product_id+"&order="+o.order+"&r="+Math.random());
}
}
}
var o=e("biz_common/dom/event.js"),r=e("common/utils.js");
if(document.getElementsByClassName){
for(var n=document.getElementsByClassName("js_product_section"),d=document.getElementsByClassName("js_product_a"),i=[],s=0;s<n.length;++s){
var a=n[s];
a.dataset&&a.dataset.product_id&&a.dataset.order&&i.push({
dom:a,
offsetTop:a.offsetTop,
product_id:a.dataset.product_id||"",
order:a.dataset.order||"",
isReport:!1
});
}
i.length>0&&(o.on(window,"scroll",t),t());
for(var s=0;s<d.length;++s)!function(e){
o.on(e,"click",function(){
var t=e.dataset||{};
return(new Image).src="/mp/appmsgreport?action=appmsg_recom&type=2&__biz="+biz+"&ascene="+(window.ascene||-1)+"&mid="+mid+"&idx="+idx+"&sn="+sn+"&product_id="+(t.product_id||"")+"&order="+(t.order||"")+"&r="+Math.random(),
t.href?(setTimeout(function(){
location.href="http://mp.weixinbridge.com/mp/wapredirect?url="+encodeURIComponent(t.href)+"&action=appmsg_redirect&uin="+uin+"&biz="+biz+"&mid="+mid+"&idx="+idx+"&scene=0";
},300),!1):!1;
},!0);
}(d[s]);
}
});define("appmsg/outer_link.js",["biz_common/dom/event.js","appmsg/open_url_with_webview.js","biz_wap/jsapi/core.js","biz_wap/utils/mmversion.js","biz_wap/utils/ajax.js","appmsg/popup_report.js","biz_wap/utils/jsmonitor_report.js"],function(e){
"use strict";
function t(e){
e.preventDefault();
}
function i(e){
var t=e.innerHTML,i=/<img.*src=[\'\"]/,n=/background-image:(\s*)url\(/,o=/background:[^;"']+url\(/;
return i.test(t)||n.test(t)||o.test(t)?!0:!1;
}
function n(e){
var t=e.innerHTML,i=e.style.fontSize;
return 0===t.trim().length||0===parseFloat(i)?!0:!1;
}
function o(e,t){
var i=e.getElementsByClassName("weui-dialog__bd")[0],n=e.getElementsByClassName("weui-dialog")[0];
if(e.getElementsByClassName("weui-dialog__hd")&&e.getElementsByClassName("weui-dialog__hd").length>0&&n.removeChild(e.getElementsByClassName("weui-dialog__hd")[0]),
t.title&&t.desc){
var o=document.createElement("div");
o.setAttribute("class","weui-dialog__hd");
var r='<strong class="weui-dialog__title">'+t.title+"</strong>";
o.innerHTML=r,i.innerText=t.desc,n.insertBefore(o,i);
}else i.innerText=t.desc;
}
function r(e){
var r=e.container;
if(!r)return!1;
for(var _=r.getElementsByTagName("a")||[],j=0,v=_.length;v>j;++j)!function(r){
var j=_[r],v=j.getAttribute("href");
if(!v)return!1;
var b=0,h=j.innerHTML;
/^[^<>]+$/.test(h)?b=1:/^<img[^>]*>$/.test(h)&&(b=2);
var k=j.getAttribute("data-linktype"),E=j.getAttribute("href");
s.on(j,"tap",function(r){
var s=j.getAttribute("href");
if(!s)return!1;
!!e.changeHref&&!/^https?:\/\/mp\.weixin\.qq\.com\/cgi-bin\//.test(s)&&(s=e.changeHref(s,b)),
r.preventDefault();
var _="";
c[j.getAttribute("data-itemshowtype")]&&(_=c[j.getAttribute("data-itemshowtype")]);
document.getElementById("js_link_dialog_name");
return y&&(d[E]&&d[E].subject_name&&"0"===d[E].item_show_type&&d[E].title?o(y,{
title:'即将打开公众号 "'+d[E].subject_name+'" 的'+c[d[E].item_show_type],
desc:w.innerText="《"+d[E].title+"》"
}):d[E]&&d[E].subject_name&&d[E].item_show_type>=0?o(y,{
desc:'即将打开公众号 "'+d[E].subject_name+'" 的'+c[d[E].item_show_type]
}):o(y,{
desc:"即将打开新的页面"
})),r.stopPropagation(),"undefined"==typeof g[E]&&(E.indexOf("mp.weixin.qq.com/s/")>-1||E.indexOf("mp.weixin.qq.com/s?")>-1)?p.setSum(110809,6,1):"undefined"==typeof g[E]&&p.setSum(110809,7,1),
g=function(){
return d[E]&&d[E].item_show_type>=0&&s.indexOf("mp.weixin.qq.com")>-1&&(l.isIOS||l.isAndroid)&&!l.isInMiniProgram&&l.isWechat?1==j.getAttribute("clicked")?!1:(u.invoke("openWebViewUseFastLoad",{
url:s,
item_show_type:d[E].item_show_type,
openType:0,
scene:1
},function(e){
console.log("openWebViewUseFastLoad res: ",e),e&&e.err_msg&&-1==e.err_msg.indexOf("ok")?u.invoke("openUrlWithExtraWebview",{
url:s,
openType:1
},function(e){
j.setAttribute("clicked",0),e&&e.err_msg&&-1==e.err_msg.indexOf("ok")&&(window.location.href=url);
}):(j.setAttribute("clicked",0),p.setSum(28839,37,1));
}),!1):void(l.isInMiniProgram?location.href=s:(l.isAndroid||l.isIOS)&&l.isWechat?a(s,{
sample:1,
reject:function(){
location.href=s;
}
}):location.href=s);
},("1"===k||i(j)||n(j))&&m.report([2,m.getRedirectType(E),"",f?1:0,window.source,m.getUrlData(E)]),
("1"===k||i(j)||n(j))&&f?(console.log("tap img link"),y.style.display="block",y._url=E,
(i(j)||n(j))&&(p.setSum(110809,8,1),y._type="OTHER"),document.querySelector("body").addEventListener("touchmove",t,{
passive:!1
})):g(),!1;
},!0),s.on(j,"click",function(e){
("1"===k||"2"===k||i(j)||n(j))&&f&&(e.preventDefault(),e.stopPropagation());
},!0);
}(j);
}
var s=e("biz_common/dom/event.js"),a=e("appmsg/open_url_with_webview.js"),u=e("biz_wap/jsapi/core.js"),l=e("biz_wap/utils/mmversion.js"),m=(e("biz_wap/utils/ajax.js"),
e("appmsg/popup_report.js")),p=e("biz_wap/utils/jsmonitor_report.js"),c={
0:"文章",
11:"文章",
8:"图片",
7:"语音",
5:"视频"
},d={};
if("undefined"!=typeof jumpInfo)for(var _=0;_<jumpInfo.length;_++)d[jumpInfo[_].url]={
title:jumpInfo[_].title,
item_show_type:jumpInfo[_].item_show_type,
subject_name:jumpInfo[_].subject_name,
link_type:jumpInfo[_].link_type
};
var g=function(){},f=window.img_popup,y=document.getElementById("js_link_dialog"),w=(document.getElementById("js_link_dialog_head"),
document.getElementById("js_link_dialog_body"));
return s.on(document.getElementById("js_link_dialog_ok"),"tap",function(e){
e.stopPropagation(),e.preventDefault(),"OTHER"===y._type&&p.setSum(110809,10,1),
m.report([4,m.getRedirectType(y._url),"",f?1:0,window.source,m.getUrlData(y._url)]),
document.querySelector("body").removeEventListener("touchmove",t),g&&g(),y.style.display="none";
}),s.on(document.getElementById("js_link_dialog_cancel"),"tap",function(e){
e.stopPropagation(),e.preventDefault(),document.querySelector("body").removeEventListener("touchmove",t),
"OTHER"===y._type&&p.setSum(110809,9,1),y.style.display="none",m.report([3,m.getRedirectType(y._url),"",f?1:0,window.source,m.getUrlData(y._url)]);
}),r;
});define("appmsg/copyright_report.js",["common/utils.js","biz_common/dom/event.js"],function(o){
"use strict";
function i(o){
var i=["/mp/copyrightreport?action=report&biz=",biz,"&scene=",o.scene,"&user_uin=",user_uin,"&uin=",uin,"&key=",key,"&pass_ticket=",pass_ticket,"&mid=",window.mid,"&idx=",window.idx,"&source_biz=",window.source_biz,"&source_mid=",window.source_mid,"&source_idx=",window.source_idx,"&card_version=2","&show_appmsg_scene=",window.source,"&session_id=",window.sessionid,"&has_recommend_msg=",window.hasRecommendMsg,"&t=",Math.random()].join("");
window.isSg&&(i+="&from=sougou");
var e=new Image;
e.src=i.substr(0,1024);
}
function e(){
var o=__appmsgCgiData;
if("2"==o.copyright_stat){
for(var i=r("copyright_info"),e=r("js_article");i&&e!==i;)c.copyright_top+=i.offsetTop,
i=i.offsetParent;
t.on(window,"scroll",n),n();
}
}
function n(){
var o=window.pageYOffset||document.documentElement.scrollTop;
o+s.getInnerHeight()>c.copyright_top&&(i({
scene:"1",
card_pos:"0"
}),t.off(window,"scroll",n),n=c.copyright_top=null);
}
function r(o){
return document.getElementById(o);
}
var s=o("common/utils.js"),t=o("biz_common/dom/event.js"),c={
copyright_top:0
};
return{
card_click_report:i,
card_pv_report:e
};
});var _extends=Object.assign||function(e){
for(var t=1;t<arguments.length;t++){
var i=arguments[t];
for(var a in i)Object.prototype.hasOwnProperty.call(i,a)&&(e[a]=i[a]);
}
return e;
};
define("appmsg/async.js",["biz_wap/ui/weui.js","biz_common/utils/string/html.js","appmsg/reward_utils.js","appmsg/pay_read_utils.js","appmsg/pay_report_utils.js","pages/create_txv.js","pages/video_ctrl.js","biz_common/utils/url/parse.js","appmsg/img_copyright_tpl.html.js","appmsg/appmsgext.js","appmsg/share_tpl.html.js","biz_common/dom/event.js","biz_wap/utils/ajax.js","biz_wap/jsapi/core.js","biz_common/tmpl.js","complain/localstorage.js","appmsg/log.js","rt/appmsg/getappmsgext.rt.js","a/a_utils.js","appmsg/related_article.js","appmsg/set_font_size.js","biz_wap/utils/device.js","biz_wap/utils/mmversion.js","pages/version4video.js","appmsg/read.js","appmsg/like.js","appmsg/like_and_share.js","appmsg/set_article_read.js","appmsg/comment.js","appmsg/iframe.js","redpackage/redpacketcover.js","appmsg/more_read.js","appmsg/album_keep_read.js"],function(e){
"use strict";
function t(){
for(var t=document.getElementsByTagName("iframe"),a=[],r=0,o=t.length;o>r;++r)a.push(t[r]);
t=null;
var n=document.getElementById("js_content"),s=n.offsetWidth,_=s/p.getRatio();
window.logs.video_cnt=0;
for(var r=0,o=a.length;o>r;++r){
var d=a[r],m=d.getAttribute("data-src")||"",l=d.getAttribute("src")||m;
if(l){
var c=e("pages/version4video.js");
if(0==l.indexOf("http://z.weishi.com/weixin/player.html"))l=l.replace(/width=\d+/g,"width="+s),
l=l.replace(/height=\d+/g,"height="+_),d.width=s,d.height=_,d.style.setProperty&&(d.style.setProperty("width",s+"px","important"),
d.style.setProperty("height",_+"px","important")),d.setAttribute("src",l),window.__addIdKeyReport&&window.__addIdKeyReport("28307",10),
window.logs.video_cnt++;else{
if(/http(s)*\:\/\/v\.qq\.com\/iframe\/(preview|player)\.html\?/.test(l)){
if(!c.isShowMpVideo()){
var w;
w=i(u?d:d),w&&j.push(w),"function"==typeof window.__addIdKeyReport&&(window.__addIdKeyReport("28307",10),
c.device.inWechat&&c.device.inWindowWechat?window.__addIdKeyReport("110644",0):c.device.inWechat&&c.device.inMacWechat&&window.__addIdKeyReport("110644",1));
}
window.logs.video_cnt++;
continue;
}
/^http(s)*\:\/\/mp\.weixin\.qq\.com\/mp\/readtemplate\?t=pages\/video_player_tmpl/.test(l)&&window.logs.video_cnt++;
}
}
}
j.length>0&&"function"==typeof window.__getVideoWh&&h.on(window,"resize",function(){
try{
for(var e=0,t=j.length;t>e;e++){
var i=j[e],a=i.playerObj;
if(a){
var r=window.__getVideoWh(i);
i.style.width=r.w+"px",i.style.height=r.h+"px",a.resize({
width:r.vw,
height:r.vh
});
}
}
}catch(o){}
},!1);
}
function i(e){
var t=e.getAttribute("data-src")||e.getAttribute("src"),i=l.getQuery("vid",t),r=e.getAttribute("data-vw"),o=e.getAttribute("data-vh"),n=e.getAttribute("data-ratio"),s=document.createElement("span");
s.setAttribute("data-ratio",n),s.id="js_tx_video_container_"+Math.random(),s.className="js_tx_video_container",
s.style.cssText=e.style.cssText,s.style.display="none";
var _=e.parentNode;
return _?(_.lastChild===e?_.appendChild(s):_.insertBefore(s,e.nextSibling),m.createTxVideo({
containerId:s.id,
vid:i,
width:r,
height:o,
autoplay:!1,
allowFullScreen:!0,
onSuccess:function(e){
s.playerObj=e.player,a(s,i),s.style.display="block";
},
onError:function(){}
}),_.removeChild(e),s):void 0;
}
function a(e,t){
if(t&&e){
var i=e.parentNode;
if(i){
for(var a=[],r=0,o=i.children.length;o>r;r++){
var n=i.children[r];
n.className.indexOf("img_loading")>=0&&n.getAttribute("data-vid")==t&&a.push(n);
}
for(var r=0,o=a.length;o>r;r++)i.removeChild(a[r]);
e.style.display="block";
}
}
}
function r(e){
if(e&&e.img_copy_info&&e.img_copy_info.list){
for(var t={},i=e.img_copy_info.list,a=window.__appmsgCgiData.copyright_stat,r=window.__appmsgCgiData.source_biz,o=0,n=i.length;n>o;o++){
var s=i[o];
if(2==s.type){
if(2==a&&r==s.source_uin)continue;
t[s.img_url]={
source_nickname:s.source_nickname,
source_uin:s.source_uin,
source_encode_biz:s.source_encode_biz||""
};
}
}
for(var _=document.getElementsByTagName("img"),o=0,n=_.length;n>o;o++){
var s=_[o],d=s.getAttribute("data-src")||s.getAttribute("data-backsrc")||"";
if(t[d]){
var m=document.createElement("div");
m.innerHTML=y.tmpl(c,t[d],!1);
{
var p=m.children[0],l=s.parentNode,w=l.insertBefore(p,s),g=w.children[0];
(function(e,t){
h.on(t,"click",function(){
var t="https://mp.weixin.qq.com/mp/profile_ext?action=home&__biz="+e.source_encode_biz+"&scene=112#wechat_redirect";
return-1!=navigator.userAgent.indexOf("WindowsWechat")||-1!=navigator.userAgent.indexOf("Mac OS")?(location.href=t,
!1):(f.invoke("openUrlWithExtraWebview",{
url:t,
openType:1
},function(e){
-1==e.err_msg.indexOf("ok")&&(location.href=t);
}),!1);
});
})(t[d],g);
}
w.insertBefore(s,g);
}
}
}
}
function o(t){
var i=t.appmsgstat||{},a=t.appmsgact||{},r=t.paySubscribeInfo||{};
if(window.paySubscribeInfo=r,window.isFans=t.is_fans,window.appmsgstat||(window.appmsgstat=i),
i.show_read){
var o=document.getElementById("js_read_area3"),n=document.getElementById("readNum3");
if(!o||!n)return;
var d=e("appmsg/read.js");
d.showReadNum({
show:!0,
readAreaDom:o,
readNumDom:n,
readAreaDisplayValue:window.isPaySubscribe?"none":"block",
readNum:window.is_temp_url?window.read_num:i.read_num
});
}
if(f.invoke("handleHaokanAction",{
imgUrl:ori_head_img_url?ori_head_img_url:"",
link:msg_link.html(!1),
desc:msg_desc?msg_desc:"",
title:msg_title?msg_title.htmlDecode():"",
action:"update_recommend_status",
permission:window.is_temp_url||i.show_like_gray||!i.show_like||2!==appmsg_like_type?0:1,
recommend:i.liked?1:0
},function(){}),i.show_like){
var m=e("appmsg/like.js"),p=document.getElementById("like3"),l=document.getElementById("likeNum3");
if(!p||!l)return;
i.liked=window.is_temp_url?window.liked:i.liked;
var c=1===appmsg_like_type?"praised":"like_btn_liked";
m.showLikeNum({
show:!0,
likeAreaDom:p,
likeNumDom:l,
liked:i.liked,
className:c,
likeAreaDisplayValue:"inline",
likeNum:window.is_temp_url?window.like_num:i.like_num,
likeGray:!!i.show_like_gray
}),m.initLikeEvent({
likeAreaDom:p,
likeNumDom:l,
className:c,
prompted:i.prompted,
biz:window.biz,
mid:window.mid,
idx:window.idx,
appmsgid:window.appmsgid,
itemidx:window.itemidx,
is_temp_url:window.is_temp_url,
showType:i.style
});
}
var w=e("appmsg/like_and_share.js");
w.initLikeShareDom({
shareShow:t.share_flag&&!!t.share_flag.show&&!I.isInMiniProgram,
shareGray:t.share_flag&&!!t.share_flag.show_gray,
likeShow:!!i.show_old_like,
likeGray:!!i.show_old_like_gray,
likeNum:i.old_like_num?i.old_like_num:0,
isLike:i.old_liked?1:0,
isZaikan:i.show_like?1:0
});
var g=e("appmsg/set_article_read.js"),u=g.bindArticleReadEvent;
u();
var y=t.share_flag&&t.share_flag.show;
if(i&&!i.show_like&&!i.show_old_like&&!y){
var v=document.getElementById("js_bottom_opr_right");
v&&(v.style.display="none"),document.getElementById("js_bottom_opr_right")&&(document.getElementById("js_bottom_opr_right").style.display="none");
}
if(1===t.comment_enabled){
var j=e("appmsg/comment.js");
j.initComment(t);
}
b.setBackgroundClass(),s.init(_extends({
isFans:t.is_fans
},t.reward),{
reward_entrance_enable_for_preview:t.reward_entrance_enable_for_preview,
reward_wording:t.reward_wording,
reward_author_head:t.reward_author_head
}),window.isPaySubscribe&&_.init(r,{
rewardTotal:t.reward.reward_total||0,
rewardTotalCut:t.reward.is_reward_total_count_cut
});
var E=document.getElementById("js_cmt_container");
if(1==t.comment_entrance_enable_for_preview&&window.is_temp_url&&E&&(E.style.display="block"),
t.comment_entrance_enable_for_preview&&(document.getElementById("js_preview_cmt")&&(document.getElementById("js_preview_cmt").style.display="block"),
h.on(document.getElementById("js_preview_cmt_write"),"tap",function(e){
e.preventDefault(),window.weui.alert("预览状态下无法操作");
})),t.comment_enabled&&E&&(E.style.display="block"),I.isIOS&&"block"===E.style.display&&location.href.match(/fontScale=\d+/)&&z.os.ipad&&z.os.getNumVersion()>=13){
var S=location.href.match(/fontScale=(\d+)/);
x(E,parseFloat(S[1])/100);
}
k&&(i.old_liked||a.old_liked_before?k.render("praise",!0):i.liked||a.seen_before?k.render("like",!0):a.favorite_before?k.render("favorite",!0):a.share_before?k.render("share",!0):(k.isFromRecommend||!window.is_login)&&k.render("other",!0));
}
function n(){
var t=0,i="27613",a="50";
w.getData({
biz:biz,
appmsg_type:appmsg_type,
mid:mid,
sn:sn,
idx:idx,
scene:source,
title:msg_title,
ct:ct,
abtest_cookie:abtest_cookie,
devicetype:devicetype,
version:window.clientversion,
is_need_ticket:j&&j.length>0?1:0,
is_need_ad:0,
comment_id:comment_id,
is_need_reward:is_need_reward,
both_ad:0,
reward_uin_count:is_need_reward?3*s.getCountPerLine({
can_reward:!0
})-1:0,
send_time:window.send_time||"",
msg_daily_idx:msg_daily_idx,
item_show_type:window.item_show_type,
is_original:t,
is_only_read:is_only_read,
req_id:window.req_id||"",
pass_ticket:pass_ticket,
is_temp_url:window.is_temp_url||0,
more_read_type:more_read_type||0,
rtId:i,
rtKey:a,
appmsg_like_type:window.appmsg_like_type,
is_pay_subscribe:window.isPaySubscribe,
pay_subscribe_uin_count:window.isPaySubscribe?3*_.getCountPerLine():0,
has_red_packet_cover:window.__appmsgCgiData.has_red_packet_cover,
onSuccess:function(t){
if(t)try{
if(window.__second_open__&&t.pay_subscribe_info&&1*t.pay_subscribe_info.is_paid!=isPaid)return d.report110809(11),
(new Image).src="https://badjs.weixinbridge.com/badjs?id=244&level=4&from="+window.encodeURIComponent(window.location.host)+"&msg="+window.encodeURIComponent(window.location.href),
void f.invoke("handleMPPageAction",{
action:"paySuccess",
fullUrl:window.location.href,
itemShowType:window.item_show_type
},function(e){
d.report110809(e.err_msg.indexOf("ok")>-1?19:20),window.localStorage&&window.localStorage.setItem&&window.localStorage.setItem("isPaid-"+window.biz+"-"+window.mid+"-"+window.idx,"1"),
window.location.href=window.location.href+"&r="+Math.random()+"#wechat_redirect";
});
if(t&&t.base_resp&&t.base_resp.wxtoken&&(window.wxtoken=t.base_resp.wxtoken),window.fromWeixinCached&&e("appmsg/iframe.js"),
r(t),t.ret)return;
if(t.red_packet_cover_data&&t.red_packet_cover_data.cover_uri_data&&t.red_packet_cover_data.cover_uri_data.length>0){
var n=e("redpackage/redpacketcover.js");
n.render({
list:t.red_packet_cover_data.cover_uri_data
});
}
var s=document.getElementById("js_more_read_area");
if(s&&t&&t.more_read_list&&t.more_read_list.length&&e("appmsg/more_read.js")(s,t.more_read_list),
window.isFans=t.is_fans,o({
appmsgstat:t.appmsgstat,
appmsgact:t.appmsgact,
comment_enabled:t.comment_enabled,
comment_count:t.comment_count,
only_fans_can_comment:t.only_fans_can_comment,
only_fans_days_can_comment:t.only_fans_days_can_comment,
is_fans_days:t.is_fans_days,
reward:{
reward_total:t.reward_total_count,
is_reward_total_count_cut:t.is_reward_total_count_cut,
reward_head_imgs:t.reward_head_imgs||[],
can_reward:t.can_reward,
user_can_reward:t.user_can_reward,
reward_qrcode_ticket:t.reward_qrcode_ticket,
timestamp:t.timestamp,
reward_author_head:t.reward_author_head,
rewardsn:t.rewardsn,
scene:source,
is_need_reward:is_need_reward,
title:msg_title,
author_id:author_id,
appmsgextRtId:i,
appmsgextRtKey:a,
can_whisper:t.can_whisper
},
reward_entrance_enable_for_preview:t.reward_entrance_enable_for_preview,
reward_wording:t.reward_wording,
reward_author_head:t.reward_author_head,
comment_entrance_enable_for_preview:t.comment_entrance_enable_for_preview,
share_redirect_url:t.share_redirect_url||"",
logo_url:t.logo_url,
nick_name:t.nick_name,
is_fans:t.is_fans,
paySubscribeInfo:t.pay_subscribe_info,
share_flag:t.share_flag,
test_flag:t.test_flag
}),t.appmsg_album_extinfo){
var _=e("appmsg/album_keep_read.js");
_.init(t.appmsg_album_extinfo);
}
}catch(m){
v("[Appmsg] error parse async data, biz="+biz+", mid="+mid);
var p=new Image;
return p.src=("http://mp.weixin.qq.com/mp/jsreport?1=1&key=1&content=biz:"+biz+",mid:"+mid+",uin:"+uin+"[key1]"+encodeURIComponent(m.toString())+"&r="+Math.random()).substr(0,1024),
console&&console.error(m),void("undefined"!=typeof window.WX_BJ_REPORT&&window.WX_BJ_REPORT.BadJs&&WX_BJ_REPORT.BadJs.onError(m));
}
},
onError:function(){
var e=new Image;
e.src="http://mp.weixin.qq.com/mp/jsreport?1=1&key=2&content=biz:"+biz+",mid:"+mid+",uin:"+uin+"[key2]ajax_err&r="+Math.random();
}
});
}
e("biz_wap/ui/weui.js"),e("biz_common/utils/string/html.js");
var s=e("appmsg/reward_utils.js"),_=e("appmsg/pay_read_utils.js"),d=e("appmsg/pay_report_utils.js"),m=e("pages/create_txv.js"),p=e("pages/video_ctrl.js"),l=e("biz_common/utils/url/parse.js"),c=e("appmsg/img_copyright_tpl.html.js"),w=e("appmsg/appmsgext.js"),g=(e("appmsg/share_tpl.html.js"),
navigator.userAgent),u=-1!=g.indexOf("MicroMessenger"),h=(-1!=navigator.userAgent.indexOf("WindowsWechat"),
e("biz_common/dom/event.js")),f=(e("biz_wap/utils/ajax.js"),e("biz_wap/jsapi/core.js")),y=e("biz_common/tmpl.js"),v=(e("complain/localstorage.js"),
e("appmsg/log.js")),b=(e("rt/appmsg/getappmsgext.rt.js"),e("a/a_utils.js")),k=e("appmsg/related_article.js"),j=[],x=e("appmsg/set_font_size.js").setFontSize,z=e("biz_wap/utils/device.js"),I=e("biz_wap/utils/mmversion.js");
t(),n();
});define("biz_wap/ui/lazyload_img.js",["biz_wap/utils/mmversion.js","biz_common/dom/event.js","biz_common/dom/attr.js","biz_common/ui/imgonepx.js"],function(t){
"use strict";
function i(){
var t=this.images;
if(!t||t.length<=0)return!1;
var i=window.pageYOffset||document.documentElement.scrollTop,e=window.innerHeight||document.documentElement.clientHeight,o=this.offset||60,a=0;
if("wifi"==window.networkType){
var r={
bottom:1,
top:1
};
this.lazyloadHeightWhenWifi&&(r=this.lazyloadHeightWhenWifi()),o=Math.max(r.bottom*e,o),
a=Math.max(r.top*e,a);
}
for(var s=+new Date,c=[],d=this.sw,f=this,p=-1,g=0,u=t.length;u>g;g++)!function(t,i){
var r=t.placeholder.getBoundingClientRect(),s=t.src;
if(s){
(s.match(/\:\/\/[^\/]+\/mmbiz\//)&&s.indexOf("wx_fmt=gif")>-1||s.match(/\:\/\/[^\/]+\/mmbiz_gif\//))&&p++;
var f=a,g=o;
(s.match(/\:\/\/[^\/]+\/mmbiz\//)&&s.indexOf("wx_fmt=gif")>-1||s.match(/\:\/\/[^\/]+\/mmbiz_gif\//))&&m&&(f=0,
g=60),!t.show&&(r.top<=0&&r.top+r.height+f>=0||r.top>0&&r.top<e+g)&&(i.inImgRead&&(r.top<=0&&r.top+r.height>=0||r.top>0&&r.top<e)&&i.inImgRead(s,networkType),
i.changeSrc&&(s=i.changeSrc(t.loader,s,p,t.placeholder)),t.loader.onerror=function(){
var e=this;
!!i.onerror&&i.onerror(t.loader.src,e,t.placeholder);
},t.loader.onload=function(){
var e=this;
if("data:image/gif;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAYAAAAfFcSJAAAADUlEQVQImWNgYGBgAAAABQABh6FO1AAAAABJRU5ErkJggg=="!=e.src){
e.style.cssText=t.placeholder.style.cssText;
var o=e.getAttribute("data-forceheight");
o?(e.removeAttribute("data-forceheight"),h(e,"height",o,"important")):h(e,"height","auto","important"),
e.getAttribute("_width")?h(e,"width",e.getAttribute("_width"),"important"):h(e,"width","auto","important"),
t.placeholder.parentNode.replaceChild(e,t.placeholder),t.placeholder=e,!!i.onload&&i.onload(e.src,e);
}
},l(t.loader,"src",s),c.push(s),t.show=!0,h(t.placeholder,"visibility","visible","important")),
n.isWp&&1*t.placeholder.width>d&&(t.placeholder.width=d);
}
}(t[g],f);
c.length>0&&this.detect&&this.detect({
time:s,
loadList:c,
scrollTop:i
});
}
function e(){
var t=document.getElementsByTagName("img"),e=[],o=this.container,a=this.attrKey||"data-src",n=o.offsetWidth,r=0,s=this.imgOccupied||!1,m=this.crossOrigin||!1;
o.currentStyle?r=o.currentStyle.width:"undefined"!=typeof getComputedStyle&&(r=getComputedStyle(o).width),
this.sw=1*r.replace("px","");
for(var d=0,f=t.length;f>d;d++){
var p=t.item(d),g=l(p,a),u=l(p,"src");
if(g&&!(u&&u.indexOf("data:image/gif;base64")<0)){
var w=100;
if(p.dataset&&p.dataset.ratio){
var A=1*p.dataset.ratio,b=1*p.dataset.w||n;
"number"==typeof A&&A>0?(b=n>=b?b:n,w=b*A,s||(p.style.width&&p.setAttribute("_width",p.style.width),
h(p,"width",b+"px","important"),h(p,"visibility","visible","important"),p.setAttribute("src",c))):h(p,"visibility","hidden","important");
}else h(p,"visibility","hidden","important");
s||h(p,"height",w+"px","important"),m&&-1==g.indexOf("mmsns.qpic.cn")&&!(g.match(/\:\/\/[^\/]+\/mmbiz\//)&&g.indexOf("wx_fmt=gif")>-1||g.match(/\:\/\/[^\/]+\/mmbiz_gif\//))&&(p.crossOrigin="anonymous"),
p.alt="图片",e.push({
placeholder:p,
loader:p.cloneNode(),
src:g,
height:w,
show:!1
});
}
}
this.images=e,i.call(this);
}
function o(t){
if(this.__called_first_time)i.call(this,t),this.__called_first_time=!1;else if(!this.debounce){
this.debounce=!0;
var e=this;
setTimeout(function(){
i.call(e,t),e.debounce=!1;
},500);
}
}
function a(t){
r.on(window,"scroll",function(i){
o.call(t,i);
}),setTimeout(function(){
e.call(t,{});
},0),r.on(document,"touchmove",function(i){
o.call(t,i);
}),t.__called_first_time=!0,o.call(t,{});
}
var n=t("biz_wap/utils/mmversion.js"),r=t("biz_common/dom/event.js"),s=t("biz_common/dom/attr.js"),l=s.attr,h=s.setProperty,c=t("biz_common/ui/imgonepx.js"),m=!0;
return a;
});