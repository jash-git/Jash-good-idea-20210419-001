define("appmsg/img_copyright_tpl.html.js",[],function(){
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
function e(){
return!1;
}
function t(){
return-1!=r.indexOf("&dd=1")?!1:"54"==parent.window.appmsg_type?!1:!0;
}
function o(){
var i;
if(parent==window)i=window;else try{
{
parent.window.__videoDefaultRatio;
}
i=parent.window;
}catch(n){
i=window;
}
var e=i.__videoDefaultRatio||16/9;
return"54"==i.appmsg_type?e:e;
}
var r=window.location.href;
return{
showPauseTips:t,
showVideoLike:e,
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
});define("appmsg/pay_read_utils.js",["biz_wap/ui/weui.js","biz_wap/jsapi/core.js","biz_common/dom/event.js","biz_wap/utils/mmversion.js","biz_wap/utils/device.js","appmsg/pay_report_utils.js","common/utils.js"],function(e){
"use strict";
e("biz_wap/ui/weui.js");
var i=e("biz_wap/jsapi/core.js"),n=e("biz_common/dom/event.js"),r=e("biz_wap/utils/mmversion.js"),a=e("biz_wap/utils/device.js"),t=e("appmsg/pay_report_utils.js"),o=e("common/utils.js"),s=function(e){
var i=arguments.length<=1||void 0===arguments[1]?document:arguments[1];
return i.querySelector(e);
},d=window.payFreeGift,w=document.documentElement&&document.documentElement.clientWidth||window.innerWidth;
try{
var u=s("#img-content");
if(u){
var _=u.getBoundingClientRect();
_.width&&(w=_.width);
}
}catch(p){
console.error(p);
}
var c=32,l=8,m='<div class="pay__tag-reward js_reward"></div>',f={
dom:{
payFee:[s("#js_pay_panel .js_pay_fee"),s("#js_pay_panel_bottom .js_pay_fee")],
wrap:s("#js_pay_wall_wrap"),
payNum:s("#js_pay_num"),
rewardNumWrap:s("#js_pay_reward_num_wrap"),
rewardNum:s("#js_pay_reward_num"),
wall:s("#js_pay_wall"),
giftBar:s("#js_pay_gift_bar"),
sendGift:s("#js_send_pay_gift")
},
perLine:null,
data:{}
},y=function(e){
e&&(/^http/.test(e)||(e=location.protocol+"//"+location.host+e),e.indexOf("#")<0&&(e+="#wechat_redirect"),
-1!==navigator.userAgent.indexOf("MicroMessenger")&&(r.isIOS||r.isAndroid||r.isWp)?i.invoke("openUrlWithExtraWebview",{
url:e,
openType:1
},function(i){
-1===i.err_msg.indexOf("ok")&&(location.href=e);
}):location.href=e);
},g=function(){
var e=f.dom,i=f.data,n=parseInt(i.pay_cnt,10);
e.payNum.innerHTML=n>=1e4||i.is_pay_cnt_cut?"en"===window.LANG?"10k+":"1万+":n+"",
i.rewardTotal?(e.rewardNum.innerHTML=i.rewardTotal+(i.rewardTotalCut?"+":""),e.rewardNumWrap.style.display=""):e.rewardNumWrap.style.display="none";
for(var r=3*f.perLine,a="",t=0,o=i.pay_head_imgs.length;o>t;t++){
var s=i.reward_status_list?i.reward_status_list[t]:0;
if(a+='<div class="pay__avatar-wrp"><img src="'+i.pay_head_imgs[t]+'">'+(s?m:"")+"</div>",
t>=r-1)break;
}
e.wall.innerHTML=a;
},h=function(){
var e=f.dom;
n.tap(e.payNum,function(){
y("/mp/paysub?action=evaluate_show_page&__biz="+window.biz+"&mid="+window.mid+"&idx="+window.idx+"&sn="+window.sn+"&link="+encodeURIComponent(window.msg_link)+"&from_scene="+window.source+"&from_subscene="+window.subscene+"&is_fans="+window.isFans);
}),n.tap(e.rewardNum,function(){
var e=(Math.ceil((o.getInnerHeight()-188)/42)+1)*Math.floor((w-15)/42);
y("/mp/reward?act=getrewardheads&__biz="+window.biz+"&appmsgid="+window.mid+"&idx="+window.idx+"&sn="+window.sn+"&offset=0&count="+e+"&source=1");
}),n.tap(e.sendGift,function(){
if(a.os.iphone||a.os.ipad||a.os.android){
var e=f.data.gift_url.html(),i="",n=e.indexOf("#");
-1!==n&&(i=e.substring(n),e=e.substring(0,n)),y(e+"&sessionid="+window.sessionid+"&enterid="+window.enterid+"&scene="+window.source+"&subscene="+window.subscene+i);
}else window.weui.alert("请使用移动端微信打开");
});
},v=function(e,i,n){
if(window.isPaySubscribe){
var a=f.dom;
if(e=JSON.parse(JSON.stringify(e)),!e.fee||window.isPaid||window.IAPProductInfo||!function(){
var i=Math.floor(e.fee/100);
a.payFee.forEach(function(e){
!window.iapPriceInfo.currency_symbol&&(e.innerHTML="￥"+i+".00"),e.parentNode.dataset.ready=1;
});
}(),r.isIOS&&e.fee&&(window.IAPProductInfo?("CNY"!==window.IAPProductInfo.currencyCode&&t.report110809(40),
t.reportOverseaPay(window.IAPProductInfo.currencyCode,100*window.IAPProductInfo.price.toFixed(2),1,window.IAPProductInfo.invokeTime,window.IAPProductInfo.countryCode,0,window.IAPProductInfo.err_msg+(window.IAPProductInfo.err_desc?"__"+window.IAPProductInfo.err_desc:""))):window.oriProductFee=Math.floor(e.fee/100)),
e.pay_cnt){
if(e.is_paid&&!d){
e.pay_head_imgs.unshift(e.my_head_img),e.reward_status_list instanceof Array?e.reward_status_list.unshift(e.my_reward_status):e.reward_status_list=[e.my_reward_status];
var o=3*f.perLine;
e.pay_head_imgs.length>o&&(e.pay_head_imgs=e.pay_head_imgs.slice(0,o));
}
e.rewardTotal=i.rewardTotal,e.rewardTotalCut=i.rewardTotalCut,f.data=e,a.wrap.style.height="",
a.wrap.style.marginTop="",a.wrap.style.visibility="visible",g(),!n&&h();
}else a.wrap.style.display="none";
a.giftBar&&(a.giftBar.style.display=window.payGiftsCount-e.gifted_count>0&&!d?"":"none");
}
},b=function(){
if(!window.isPaySubscribe)return 0;
if(null===f.perLine){
var e=c+l;
f.perLine=Math.floor(.8*w/e),f.dom.wall.parentNode.style.width=f.perLine*e-l+"px";
}
return f.perLine;
};
return{
init:v,
getCountPerLine:b
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
});define("appmsg/share_biz.js",[],function(){
"use strict";
var e=[2390745668,3099420829,3872121626,3203738065,3072206507,3566970574,3002803029,3099387730,3559965496,3525314097,2390323860,3084276724,3289028514,3003793452,3003972371,2398512110,3071748654,3233018348,3095049467,3076061592,3273032305,3264278949,3086344434,3014829842,3294546013,2058310401,2397841479,2397640820,3282179238,3072107639,3521076442,3554888231,2397274880,2394106525,3077726226,2103095721,3593723769,2395186785,2393698643,3944000110,2397445840,2394144447,3082139483,3070806332,3016714421,3006879186,3213574124,3221398587,3078448935,3591999034,3551390431];
return{
shareBizTest:e
};
});var _extends=Object.assign||function(e){
for(var t=1;t<arguments.length;t++){
var i=arguments[t];
for(var n in i)Object.prototype.hasOwnProperty.call(i,n)&&(e[n]=i[n]);
}
return e;
};
define("appmsg/related_article.js",["biz_common/utils/string/html.js","biz_common/tmpl.js","biz_wap/utils/ajax.js","biz_wap/jsapi/core.js","appmsg/related_article_tpl.html.js","appmsg/related_article_item.html.js","biz_wap/utils/openUrl.js","biz_common/dom/event.js","common/utils.js","biz_common/dom/class.js","biz_common/utils/url/parse.js","common/comm_report.js","appmsg/related_article_feedback.js","biz_wap/utils/mmversion.js","biz_wap/utils/device.js","appmsg/set_font_size.js","biz_wap/utils/jsmonitor_report.js","pages/utils.js","pages/scrollY.js"],function(e){
"use strict";
e("biz_common/utils/string/html.js");
var t=e("biz_common/tmpl.js"),i=e("biz_wap/utils/ajax.js"),n=e("biz_wap/jsapi/core.js"),o=e("appmsg/related_article_tpl.html.js"),a=e("appmsg/related_article_item.html.js"),r=e("biz_wap/utils/openUrl.js"),s=e("biz_common/dom/event.js"),l=e("common/utils.js"),d=e("biz_common/dom/class.js"),m=e("biz_common/utils/url/parse.js"),c=e("common/comm_report.js"),u=e("appmsg/related_article_feedback.js"),p=e("biz_wap/utils/mmversion.js"),_=e("biz_wap/utils/device.js"),w=e("appmsg/set_font_size.js").setFontSize,g=e("biz_wap/utils/jsmonitor_report.js"),h=e("pages/utils.js"),f=h.getId,j=h.getByClass,b=h.qs,v=h.formatReadNum,y=h.getScrollTop,z=e("pages/scrollY.js"),x=l.getInnerHeight(),T={
bottomOpr:f("js_bottom_opr_right"),
container:f("js_related_container")
};
if(null===T.container)return null;
var R=0,I=!1,B=null,C=null,O=!1,E=3,F=100*Math.random()<1;
F&&window.WX_BJ_REPORT.BadJs.report("relatedArticleFlag","value:"+window.relatedArticleFlag,{
mid:"mmbizwap:related_monitor",
uin:window.user_uin
});
var P=_.os.ipad||!p.isIOS&&!p.isAndroid,A=0;
p.isIOS?A=1:p.isAndroid&&(A=2);
var S={
Bizuin_from:window.biz,
Msgid_from:window.parseInt(window.mid,10)||0,
Itemidx_from:window.parseInt(window.idx,10)||0,
Scene:window.parseInt(window.source,10)||0,
Subscene:window.parseInt(window.subscene,10)||0,
Sessionid:window.sessionid||"",
Enterid:window.parseInt(window.enterid,10)||0
},W=[{
name:"内容质量低",
value:1
},{
name:"不看此公众号",
value:2
}];
F&&window.WX_BJ_REPORT.BadJs.report("RELATED_ARTICLE_COUNT","count:"+E,{
mid:"mmbizwap:related_monitor",
uin:window.user_uin
});
var k=function(e){
var t=document.createElement("div");
return t.innerHTML=e,t.childNodes;
},J=function(){
null!==B&&(s.off(T.area,"transitionend",B),B=null);
};
B=function(e){
e.target===T.area&&"height"===e.propertyName&&(T.area.style.overflow="visible",J());
};
var L=function(e,t){
var i=2.25,n=6.5,o=0;
return 0===e?(T.area.style.overflow="hidden",T.area.style.margin="0",J()):(T.area.style.margin="12px 0",
o=e*n+i),T.area.style.height=o+"em",O&&e&&B&&B({
target:T.area,
propertyName:"height"
}),t?(R||(R=T.placeholder?b("div",T.placeholder).getBoundingClientRect().height:b(".js_related_item",T.list).getBoundingClientRect().height),
e*R+b(".js_related_title",T.main).getBoundingClientRect().height):void 0;
},M=function(e){
null!==C?(clearTimeout(C),C=null,"function"==typeof e&&e(!0)):"function"==typeof e&&e(!1);
},H=function(){
var e=!1,t=[],n=function o(n){
e=!0,i({
url:"/mp/relatedarticle?action=expose",
type:"POST",
dataType:"json",
data:n,
complete:function(){
t.length?o(t.shift()):e=!1;
}
});
};
return function(i){
e?t.push(i):n(i);
};
}(),N=function(){
for(var e=j("js_related_item"),t=y(),i=[],o=0;o<e.length;o++){
var a=e[o];
1*a.dataset.hasreport!==1&&a.clientHeight+a.offsetTop>=t+a.clientHeight/2&&a.clientHeight+a.offsetTop<=t+a.clientHeight/2+l.getInnerHeight()&&!function(e,t){
var n=e.dataset,o=n.url;
n.hasreport=1,g.setSum(110809,21,1),c.report(18832,_extends({
Actiontype:1,
Type:1,
Bizuin:m.getQuery("__biz",o),
Msgid:window.parseInt(m.getQuery("mid",o),10)||0,
Itemidx:window.parseInt(m.getQuery("idx",o),10)||0,
Sendtimestamp:window.parseInt(n.time)||0,
Pos:t+1,
Recalltype:1*n.recalltype,
Mmversion:A,
Isreaded:1*n.isreaded,
ExpType:n.exptype,
ExtInfo:n.ext_info
},S)),H({
bizuin:n.bizuin,
mid:n.mid,
idx:n.idx
}),i.push({
item_show_type:n.item_show_type,
url:o
});
}(a,o);
}
i.length&&n.invoke("downloadPageDataForFastLoad",{
itemList:i
},function(e){
console.log("downloadPageDataForFastLoad",e);
});
},U=function(e){
return 1===window.show_related_article||e.indexOf(window.source)>-1||e.indexOf(window.subscene)>-1;
}(["157","169"]),Q=function(){
var e=arguments.length<=0||void 0===arguments[0]?0:arguments[0],n=arguments.length<=1||void 0===arguments[1]?E:arguments[1],o=parseFloat(window.getComputedStyle(T.main).marginTop),r=function(e){
if(O)L(e);else{
var t=24,i=T.area.getBoundingClientRect().top,n=L(e,!0)+t+o,a=T.bottomOpr.getBoundingClientRect().top,r=i+n;
if(!(a>x||0>r)){
var s=i-t;
s>0&&x>r||z(0>s?{
distance:s,
duration:.5,
end:N
}:{
distance:r-x,
duration:.5,
end:N
});
}
}
C=null;
};
C=setTimeout(function(){
return r(3);
},500),i({
url:"/mp/relatedarticle?action=getlist&count="+n+"&begin="+e+"&article_url="+window.encodeURIComponent(location.href)+"&__biz="+window.biz+"&mid="+window.mid+"&idx="+window.idx+"&has_related_article_info="+window.hasRelatedArticleInfo+"&is_from_recommand="+(U?1:0),
type:"GET",
dataType:"json",
success:function(i){
i&&i.base_resp&&1*i.base_resp.ret===0&&i.list&&i.list.length?!function(){
var o=i.list.map(function(e){
return U&&(e.url=e.url.replace(/#wechat_redirect/,"&show_related_article=1$&")),
e.like_num_wording=e.old_like_num?v(e.old_like_num):"",e.read_num_wording=e.read_num?v(e.read_num):"",
e.pay_cnt_wording=e.pay_cnt?v(e.pay_cnt):"",e.ext_info=e.ext_info.html(!0),e;
});
F&&window.WX_BJ_REPORT&&window.WX_BJ_REPORT.BadJs.report("list.length","list.length:"+o.length,{
mid:"mmbizwap:related_monitor",
_info:{
relatedArticleFlag:window.relatedArticleFlag,
isPc:P
},
uin:window.user_uin
}),o.length!==n&&window.WX_BJ_REPORT&&window.WX_BJ_REPORT.BadJs.report("list is no match","list.length:"+o.length+"|count:"+n,{
mid:"mmbizwap:related_monitor",
_info:{
relatedArticleFlag:window.relatedArticleFlag,
list:o,
isPc:P
},
uin:window.user_uin
});
var s=document.createDocumentFragment();
Array.prototype.forEach.call(k(t.tmpl(a,{
list:o,
reason:W,
begin:e
})),function(e){
s.appendChild(e.cloneNode(!0));
}),T.list.appendChild(s),R=b("div",T.placeholder).getBoundingClientRect().height,
T.placeholder.parentNode.removeChild(T.placeholder),T.placeholder=null,M(function(e){
e?r(i.list.length):L(i.list.length);
}),T.list.style.opacity=1,N(),window.ipados13_font_scale&&w(T.list,window.ipados13_font_scale/100);
}():M(function(e){
!e&&L(0);
});
}
});
},X=function(){
s.on(T.list,"click",".js_related_item",function(e){
var t=e.delegatedTarget,i=t.dataset,o=i.url;
g.setSum(110809,23,1),c.report(18832,_extends({
Actiontype:2,
Type:1,
Bizuin:m.getQuery("__biz",o),
Msgid:window.parseInt(m.getQuery("mid",o),10)||0,
Itemidx:window.parseInt(m.getQuery("idx",o),10)||0,
Sendtimestamp:window.parseInt(i.time)||0,
Pos:(1*i.index||0)+1,
Recalltype:1*i.recalltype,
Isreaded:1*i.isreaded,
Mmversion:A,
ExpType:i.exptype,
ExtInfo:i.ext_info
},S)),p.isWechat&&!p.isMpapp?n.invoke("openWebViewUseFastLoad",{
url:o,
item_show_type:i.item_show_type,
scene:132,
openType:0
},function(e){
console.log("openWebViewUseFastLoad res: ",e),e&&e.err_msg&&-1===e.err_msg.indexOf("ok")&&r.openUrlWithExtraWebview(o);
}):location.href=o;
});
var e=null,t=null;
s.on(T.list,"touchstart",".js_related_item",function(i){
i.stopPropagation(),t=i.delegatedTarget,e=setTimeout(function(){
t&&d.addClass(t,"card_custom_active"),e=null;
},100);
},!1),s.on(T.list,"touchmove",".js_related_item",function(){
e?(clearTimeout(e),e=null):t&&d.removeClass(t,"card_custom_active");
},!1),s.on(T.list,"touchend",".js_related_item",function(i){
i.stopPropagation(),setTimeout(function(){
t&&d.removeClass(t,"card_custom_active"),t=null,e&&(clearTimeout(e),e=null);
},200);
},!1),s.on(window,"scroll",N),null!==B&&s.on(T.area,"transitionend",B),u.init({
container:T.list,
biz:window.biz,
mid:window.mid,
idx:window.idx,
dislikeCb:function(e){
e.parentNode.removeChild(e),L(T.list.children.length);
}
});
};
return{
isFromRecommend:U,
render:function(e,i){
if(!I&&1*window.item_show_type===0&&""!==window.item_show_type){
if(O=i,!O){
var n=T.bottomOpr.getBoundingClientRect(),a=n.top,r=n.bottom;
if(a>x||0>r)return;
}
I=!0,T.container.innerHTML=t.tmpl(o,{
type:e
}),T.area=b(".js_related_area",T.container),O&&(T.area.style.transition="none"),
T.main=b(".js_related_main",T.area),T.list=b(".js_related_list",T.main),T.placeholder=b(".js_related_placeholder",T.main),
X(),Q();
}
}
};
});define("appmsg/malicious_wording.js",[],function(){
"use strict";
var i={
0:{
90041:"此标题包含夸大误导信息",
20012:"此标题包含低俗恶俗内容"
},
1:{
90041:"",
20012:""
},
2:{
90041:"此文章包含夸大误导信息",
20012:"此文章包含低俗恶俗内容"
}
},s={
0:{
90041:"标题使用夸大、煽动、低俗等词语造成误导或引人不适",
20012:"标题使用低俗或恶俗词语造成不正当影响或引人不适"
},
1:{
90041:"摘要包含误导、煽动的信息引人不适或造成微信用户混淆",
20012:"摘要包含低俗或恶俗内容造成不正当影响或引人不适"
},
2:{
90041:"文章包含误导、煽动的信息引人不适或造成微信用户混淆",
20012:"文章包含低俗或恶俗内容造成不正当影响或引人不适"
}
};
return{
maliciousTitleMap:i,
maliciousDescMap:s
};
});!function(n){
"use strict";
function t(n,t){
var r=(65535&n)+(65535&t),u=(n>>16)+(t>>16)+(r>>16);
return u<<16|65535&r;
}
function r(n,t){
return n<<t|n>>>32-t;
}
function u(n,u,e,o,c,f){
return t(r(t(t(u,n),t(o,f)),c),e);
}
function e(n,t,r,e,o,c,f){
return u(t&r|~t&e,n,t,o,c,f);
}
function o(n,t,r,e,o,c,f){
return u(t&e|r&~e,n,t,o,c,f);
}
function c(n,t,r,e,o,c,f){
return u(t^r^e,n,t,o,c,f);
}
function f(n,t,r,e,o,c,f){
return u(r^(t|~e),n,t,o,c,f);
}
function i(n,r){
n[r>>5]|=128<<r%32,n[(r+64>>>9<<4)+14]=r;
var u,i,h,a,g,l=1732584193,d=-271733879,v=-1732584194,C=271733878;
for(u=0;u<n.length;u+=16)i=l,h=d,a=v,g=C,l=e(l,d,v,C,n[u],7,-680876936),C=e(C,l,d,v,n[u+1],12,-389564586),
v=e(v,C,l,d,n[u+2],17,606105819),d=e(d,v,C,l,n[u+3],22,-1044525330),l=e(l,d,v,C,n[u+4],7,-176418897),
C=e(C,l,d,v,n[u+5],12,1200080426),v=e(v,C,l,d,n[u+6],17,-1473231341),d=e(d,v,C,l,n[u+7],22,-45705983),
l=e(l,d,v,C,n[u+8],7,1770035416),C=e(C,l,d,v,n[u+9],12,-1958414417),v=e(v,C,l,d,n[u+10],17,-42063),
d=e(d,v,C,l,n[u+11],22,-1990404162),l=e(l,d,v,C,n[u+12],7,1804603682),C=e(C,l,d,v,n[u+13],12,-40341101),
v=e(v,C,l,d,n[u+14],17,-1502002290),d=e(d,v,C,l,n[u+15],22,1236535329),l=o(l,d,v,C,n[u+1],5,-165796510),
C=o(C,l,d,v,n[u+6],9,-1069501632),v=o(v,C,l,d,n[u+11],14,643717713),d=o(d,v,C,l,n[u],20,-373897302),
l=o(l,d,v,C,n[u+5],5,-701558691),C=o(C,l,d,v,n[u+10],9,38016083),v=o(v,C,l,d,n[u+15],14,-660478335),
d=o(d,v,C,l,n[u+4],20,-405537848),l=o(l,d,v,C,n[u+9],5,568446438),C=o(C,l,d,v,n[u+14],9,-1019803690),
v=o(v,C,l,d,n[u+3],14,-187363961),d=o(d,v,C,l,n[u+8],20,1163531501),l=o(l,d,v,C,n[u+13],5,-1444681467),
C=o(C,l,d,v,n[u+2],9,-51403784),v=o(v,C,l,d,n[u+7],14,1735328473),d=o(d,v,C,l,n[u+12],20,-1926607734),
l=c(l,d,v,C,n[u+5],4,-378558),C=c(C,l,d,v,n[u+8],11,-2022574463),v=c(v,C,l,d,n[u+11],16,1839030562),
d=c(d,v,C,l,n[u+14],23,-35309556),l=c(l,d,v,C,n[u+1],4,-1530992060),C=c(C,l,d,v,n[u+4],11,1272893353),
v=c(v,C,l,d,n[u+7],16,-155497632),d=c(d,v,C,l,n[u+10],23,-1094730640),l=c(l,d,v,C,n[u+13],4,681279174),
C=c(C,l,d,v,n[u],11,-358537222),v=c(v,C,l,d,n[u+3],16,-722521979),d=c(d,v,C,l,n[u+6],23,76029189),
l=c(l,d,v,C,n[u+9],4,-640364487),C=c(C,l,d,v,n[u+12],11,-421815835),v=c(v,C,l,d,n[u+15],16,530742520),
d=c(d,v,C,l,n[u+2],23,-995338651),l=f(l,d,v,C,n[u],6,-198630844),C=f(C,l,d,v,n[u+7],10,1126891415),
v=f(v,C,l,d,n[u+14],15,-1416354905),d=f(d,v,C,l,n[u+5],21,-57434055),l=f(l,d,v,C,n[u+12],6,1700485571),
C=f(C,l,d,v,n[u+3],10,-1894986606),v=f(v,C,l,d,n[u+10],15,-1051523),d=f(d,v,C,l,n[u+1],21,-2054922799),
l=f(l,d,v,C,n[u+8],6,1873313359),C=f(C,l,d,v,n[u+15],10,-30611744),v=f(v,C,l,d,n[u+6],15,-1560198380),
d=f(d,v,C,l,n[u+13],21,1309151649),l=f(l,d,v,C,n[u+4],6,-145523070),C=f(C,l,d,v,n[u+11],10,-1120210379),
v=f(v,C,l,d,n[u+2],15,718787259),d=f(d,v,C,l,n[u+9],21,-343485551),l=t(l,i),d=t(d,h),
v=t(v,a),C=t(C,g);
return[l,d,v,C];
}
function h(n){
var t,r="";
for(t=0;t<32*n.length;t+=8)r+=String.fromCharCode(n[t>>5]>>>t%32&255);
return r;
}
function a(n){
var t,r=[];
for(r[(n.length>>2)-1]=void 0,t=0;t<r.length;t+=1)r[t]=0;
for(t=0;t<8*n.length;t+=8)r[t>>5]|=(255&n.charCodeAt(t/8))<<t%32;
return r;
}
function g(n){
return h(i(a(n),8*n.length));
}
function l(n,t){
var r,u,e=a(n),o=[],c=[];
for(o[15]=c[15]=void 0,e.length>16&&(e=i(e,8*n.length)),r=0;16>r;r+=1)o[r]=909522486^e[r],
c[r]=1549556828^e[r];
return u=i(o.concat(a(t)),512+8*t.length),h(i(c.concat(u),640));
}
function d(n){
var t,r,u="0123456789abcdef",e="";
for(r=0;r<n.length;r+=1)t=n.charCodeAt(r),e+=u.charAt(t>>>4&15)+u.charAt(15&t);
return e;
}
function v(n){
return unescape(encodeURIComponent(n));
}
function C(n){
return g(v(n));
}
function s(n){
return d(C(n));
}
function A(n,t){
return l(v(n),v(t));
}
function m(n,t){
return d(A(n,t));
}
n.md5=function(n,t,r){
return t?r?A(t,n):m(t,n):r?C(n):s(n);
};
}("function"==typeof jQuery?jQuery:this);define("complain/utils/const.js",[],function(A,i,g){
"use strict";
g.exports={
WRAP_TAG:"span",
IMG_TAG:"IMG",
HIGHLIGHT_ID:"highlight-id",
IMG_ID:"img-id",
CAMEL_HIGHLIGHT_ID:"highlightId",
CAMEL_IMG_ID:"imgId",
NODE_TYPE:{
text:1,
img:2
},
placeHolder:"data:image/gif;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAYAAAAfFcSJAAAADUlEQVQImWNgYGBgAAAABQABh6FO1AAAAABJRU5ErkJggg=="
};
});define("complain/utils/dom.js",["complain/utils/utils.js","complain/utils/const.js"],function(e,t,r){
"use strict";
function n(e){
for(var t=arguments.length<=1||void 0===arguments[1]?"className":arguments[1],r=arguments.length<=2||void 0===arguments[2]?y:arguments[2],n=0;n<r.length;n++)if(e[t]&&"string"==typeof e[t]&&e[t].indexOf(r[n])>-1)return!0;
return!1;
}
function a(e){
var t=e.$blockNode,r=e.$node;
if(null===t)return null;
var n=[],a=[],i=0;
for(n.push(t);n.length>0;){
var o=n.pop();
if(3===o.nodeType&&o.nodeValue!==r.nodeValue)a.push(o),i+=o.textContent.length;else if(1===o.nodeType){
if(i+=1,o===r)break;
}else if(o.nodeValue===r.nodeValue){
i+=o.textContent.length;
break;
}
for(var d=o.childNodes,s=d.length-1;s>=0;s--)n.push(d[s]);
}
return i;
}
function i(e){
var t=j(e),r=+t.dataset.index,n=0,a={
$blockNode:t,
$node:e,
paraIndex:r,
offset:n
},i=f();
return{
start:a,
end:a,
id:i
};
}
function o(e){
return e.tagName===h||3===e.nodeType?e:e.childNodes[0];
}
function d(e,t,r,n){
e.style.setProperty?(n=n||null,e.style.setProperty(t,r,n)):"undefined"!=typeof e.style.cssText&&(n=n?"!"+n:"",
e.style.cssText+=";"+t+":"+r+n+";");
}
function s(e){
if(!e)return!1;
var t=e.nodeType,r=e.tagName;
return 3===t?!1:r===h?!0:!1;
}
function u(e){
return e.reduce(function(t,r,n){
if(0===n)return r.type===x.text?t.text.push(r.data):r.type===x.img&&t.pic.push(r.data),
t;
if(r.type===x.text){
if(e[n-1].type===x.text){
var a=t.text.pop();
a+=r.data,t.text.push(a);
}else t.text.push(r.data);
return t;
}
return r.type===x.img&&t.pic.push(r.data),t;
},{
audio:[],
pic:[],
video:[],
text:[]
});
}
function p(e,t){
T[t]=e;
}
function l(e,t){
var r=i(e),n=Y([{
$node:e,
type:x.img,
idx:r.start.paraIndex
}],t),a=J(r),o=u(n);
return{
meta:{
anchorTree:n,
anchorMeta:a,
anchorBrief:o
},
range:r
};
}
function c(e,t){
var r=e.childNodes,n=t,a=null,i=0;
for(i=0;i<r.length;i++)if(a=r[i],3===a.nodeType){
var o=a.length;
if(o>n)break;
n-=o;
}
return{
$node:a,
cursor:n
};
}
var _=e("complain/utils/utils.js"),f=_.uuid,g=e("complain/utils/const.js"),m=g.WRAP_TAG,h=g.IMG_TAG,x=g.NODE_TYPE,v=["P","DIV","SECTION","LI","H1","H2","H3","H4","H5","H6","TABLE","PRE","BLOCKQUOTE"],y=["js_product_container","js_blockquote_wrap"],b=["IFRAME","VIDEO","MPVOICE","MPGONGYI","QQMUSIC","MPSHOP","MP-WEAPP","MP-MINIPROGRAM","MPPRODUCT","MPCPS"],w=["js_mpvideo"],N=["js_product_container"],T={},E=function(e){
var t=arguments.length<=1||void 0===arguments[1]?v:arguments[1];
if(!e||1!==e.nodeType)return!1;
for(var r=0;r<e.children.length;r++)if(-1!==t.indexOf(e.children[r].tagName))return!0;
return!1;
},R=function(e){
var t=e.parentNode;
return e.parentNode.removeChild(e),t.children&&t.children.length?!1:!0;
},O=function(e,t){
var r=t.getNestedStructure,a=void 0===r?!0:r,i=t.removeIgoreEle,o=void 0===i?!1:i,d=function s(e,t){
var r=e.children;
if(!r)return[];
if(!r.length)return r;
for(var a=void 0,i=[],d=0;d<r.length;d++)a=r[d],n(a,"id",w)||n(a,"className",N)?o&&(a.parentNode.removeChild(a),
d-=1):E(a,b)?o&&(R(a),d-=1):E(a,v)&&!n(a)?(i=i.concat(s(a,t)),t&&(a.getAttribute("data-index")||i.push(a))):a.getAttribute("data-index")||i.push(a);
return i;
}(e,a);
return[].slice.call(d);
};
O.paragraphStartIdx=1e6;
var k=function(e,t,r,n){
try{
e.splitText(t);
}catch(a){
"undefined"!=typeof WX_BJ_REPORT&&WX_BJ_REPORT.BadJs&&WX_BJ_REPORT.BadJs.report("ArticleMask:Error","splitText Error",{
mid:"mmbizwap:articlemask_Monitor",
view:"wap_business",
_info:{
type:"getSplitTextNode textnode",
startOffset:t,
endOffset:r
}
});
}
var i=e.nextSibling;
try{
i.splitText(r-t);
}catch(o){
"undefined"!=typeof WX_BJ_REPORT&&WX_BJ_REPORT.BadJs&&WX_BJ_REPORT.BadJs.report("ArticleMask:Error","splitText Error",{
mid:"mmbizwap:articlemask_Monitor",
view:"wap_business",
_info:{
type:"getSplitTextNode nextSibling",
startOffset:t,
endOffset:r
}
});
}
return[{
$node:i,
type:x.text,
idx:n
}];
},j=function Z(e){
return-1!==v.indexOf(e.tagName)&&"undefined"!=typeof e.dataset.index?e:Z(e.parentNode);
},P=function et(e){
return e?-1!==v.indexOf(e.tagName)?e:et(e.parentNode):e;
},$=function(e){
var t=e.start,r=e.end,n=e.$container,a=t.$node,i=t.offset,o=r.$node,d=r.offset,s=[],u=[],p=!1,l=!1,c=0;
for(s.push(n);s.length>0;){
var _=s.pop(),f=_.nodeType,g=_.tagName;
if(_.dataset&&_.dataset.index&&(c=+_.dataset.index),p&&!l&&(3===f&&u.push({
$node:_,
type:x.text,
idx:c
}),g===h&&u.push({
$node:_,
type:x.img,
idx:c
})),_===a){
if(3===f){
try{
_.splitText(i);
}catch(m){
WX_BJ_REPORT.BadJs.report("ArticleMask:Error","splitText Error",{
mid:"mmbizwap:articlemask_Monitor",
view:"wap_business",
_info:{
type:"getNodes startNode",
startOffset:i,
endOffset:d
}
});
}
var v=_.nextSibling;
u.push({
$node:v,
type:x.text,
idx:c
});
}else u.push(g===h?{
$node:_,
type:x.img,
idx:c
}:{
$node:_,
type:x.text,
idx:c
});
p=!0;
}
if(_===o||l){
if(l||(l=!0),_===o&&u.pop(),3===f){
try{
_.splitText(d);
}catch(m){
"undefined"!=typeof WX_BJ_REPORT&&WX_BJ_REPORT.BadJs&&WX_BJ_REPORT.BadJs.report("ArticleMask:Error","splitText Error",{
mid:"mmbizwap:articlemask_Monitor",
view:"wap_business",
_info:{
type:"getSplitTextNode endNode",
startOffset:i,
endOffset:d
}
});
}
u.push({
$node:_,
type:x.text,
idx:c
});
break;
}
if(g===h){
u.push({
$node:_,
type:x.img,
idx:c
});
break;
}
for(var y=_.childNodes,b=y.length-1;b>=0;b--)s.push(y[b]);
}
for(var w=_.childNodes,b=w.length-1;b>=0;b--)s.push(w[b]);
}
return u;
},B=function(e){
var t=e.start,r=e.end,n=t.$node,a=t.offset,i=r.$node,o=r.offset;
return n===i&&n instanceof Text?k(n,a,o,t.paraIndex):$(e);
},q=function(e){
return e&&(e.nodeValue||e.innerText);
},S=function(e,t,r){
var n=r===e?t:e;
if(!q(e)||!q(t))return n;
var a=(e.nodeValue||e.innerText)+(t.nodeValue||t.innerText);
return r.nodeValue=a,r.parentNode.removeChild(n),r;
},I=function(e,t){
var r=[],n=0,a=0,i=void 0;
for(r.push(e);r.length>0&&(i=r.pop(),!(3===i.nodeType&&(a=t-n,n+=i.textContent.length,
n>=t)));)for(var o=i.childNodes,d=o.length-1;d>=0;d--)r.push(o[d]);
return{
$parentNode:e,
$node:i,
offset:a
};
},C=function(e){
var t=e.$node,r=e.$parentNode,n=Number(r.dataset.index),i=a(r,t);
return{
parentIndex:n,
fromParentoffset:i
};
},A=function(){
var e=window.getSelection();
if(null===e.anchorNode)return null;
var t=e.getRangeAt(0);
if(!t||!e.toString())return null;
var r=t.startContainer,n=t.endContainer,a=t.commonAncestorContainer,i=t.startOffset,o=t.endOffset,d=j(r),s=j(n),u=d&&d.dataset.index,p=s&&s.dataset.index,l={
$blockNode:d,
$node:r,
offset:i,
paraIndex:Number(u)
},c={
$blockNode:s,
$node:n,
offset:o,
paraIndex:Number(p)
},_="string"==typeof a?a.parentNode:a,g=f();
return{
start:l,
end:c,
$container:_,
id:g
};
},M=function(e,t){
if(!e)return null;
if(3===e.nodeType){
var r=document.createElement(m);
return r.setAttribute("data-splitid",t),r.appendChild(e.cloneNode(!1)),e.parentNode&&e.parentNode.replaceChild(r,e),
r;
}
return e;
},J=function(e){
var t=e.start,r=e.end,n=e.id,i=a(t),o=t.$node===r.$node?r.offset-t.offset+i:a(r),d={
id:n,
start:{
para_offset:i,
para_index:t.paraIndex
},
end:{
para_offset:o,
para_index:r.paraIndex
}
};
return d;
},W=function(e){
return function(t){
var r=t.para_offset,n=t.para_index,a=e[n],i=[],o=0,d=0,s=void 0;
for(i.push(a);i.length>0&&(s=i.pop(),!(3===s.nodeType&&(d=r-o,o+=s.textContent.length,
o>=r)))&&!(1===s.nodeType&&(d=r-o,o+=1,o>=r));)for(var u=s.childNodes,p=u.length-1;p>=0;p--)i.push(u[p]);
return{
$blockNode:a,
$node:s,
offset:d,
paraIndex:n
};
};
},X=function(e,t,r){
var n=W(t);
return{
start:n(e.start),
end:n(e.end),
id:e.id,
$container:r
};
},z=function(e){
window.getSelection().removeAllRanges();
var t=window.getSelection(),r=document.createRange(),n=o(T.start),a=o(T.end);
r.setStart(n,e.start.offset),r.setEnd(a,e.end.offset),t.addRange(r);
},V=function(e,t){
var r=[],n=0;
for(r.push(e);r.length>0;){
var a=r.pop();
if(a===t)break;
n++;
for(var i=a.children,o=0;o<i.length;o++)r.push(i[o]);
}
return n;
},H=function(e,t){
var r=[],n=0,a=null;
for(r.push(e);r.length>0;){
var i=r.pop();
if(n===t){
a=i;
break;
}
n++;
for(var o=i.children,d=0;d<o.length;d++)r.push(o[d]);
}
return a;
},G=function(e,t){
return e&&"string"==typeof e&&-1!==e.indexOf(t)?!0:!1;
},D=function(e){
var t="rich_pages,blockquote_info,blockquote_biz,blockquote_other,blockquote_article,js_jump_icon,h5_image_link,js_banner_container,js_list_container,js_cover,js_tx_video_container,js_product_err_container,js_product_loop_content,js_product_container,img_loading,list-paddingleft-1,list-paddingleft-2,list-paddingleft-3,selectTdClass,noBorderTable,ue-table-interlace-color-single,ue-table-interlace-color-double,__bg_gif,weapp_text_link,weapp_image_link,js_img_loading,wx_video_context,db,wx_video_thumb_primary,wx_video_play_btn,wx_video_mask,qqmusic_area,tc,tips_global,unsupport_tips,qqmusic_wrp,appmsg_card_context,appmsg_card_active,qqmusic_bd,play_area,icon_qqmusic_switch,pic_qqmusic_default,qqmusic_thumb,access_area,qqmusic_songname,qqmusic_singername,qqmusic_source,js_audio_frame,share_audio_context,flex_context,pages_reset,share_audio_switch,icon_share_audio_switch,share_audio_info,flex_bd,share_audio_title,share_audio_tips,share_audio_progress_wrp,share_audio_progress,share_audio_progress_inner,share_audio_progress_buffer,share_audio_progress_loading,share_audio_progress_loading_inner,share_audio_progress_handle,share_audio_desc,share_audio_length_current,share_audio_length_total,video_iframe,vote_iframe,js_editor_vote_card,res_iframe,card_iframe,js_editor_card,weapp_display_element,js_weapp_display_element,weapp_card,app_context,weapp_card_bd,weapp_card_profile,radius_avatar,weapp_card_avatar,weapp_card_nickname,weapp_card_info,weapp_card_title,weapp_card_thumb_wrp,weapp_card_ft,weapp_card_logo,js_pay_btn,pay,pay__mask,wx_video_loading,js_redpacketcover,js_uneditable,js_uneditablemouseover,js_editor_qqmusic,js_editor_audio,ct_geography_loc_tip,js_poi_entry".split(","),r="qa__",n=[new RegExp("^weui"),new RegExp("^appmsg"),new RegExp("^audio"),new RegExp("^music"),new RegExp("^cps_inner"),new RegExp("^bizsvr_"),new RegExp("^code-snippet"),new RegExp("^"+r),new RegExp("^wx-edui-"),new RegExp("^wx_"),new RegExp("^wx-"),new RegExp("^js_darkmode__")];
if(!e)return null;
for(var a=e.split(/\s+/),i=[],o=0,d=a.length;d>o;++o){
var s=a[o];
if(s&&-1!==t.indexOf(s))i.push(s);else for(var u=0,p=n.length;p>u;u++)if(n[u].test(s)){
i.push(s);
break;
}
}
var l=i.join(".");
return l&&"."+l;
},L=function tt(e){
var t=arguments.length<=1||void 0===arguments[1]?"":arguments[1],r=arguments.length<=2||void 0===arguments[2]?document.body:arguments[2];
if(!e||e===r)return t;
var n=e.getAttribute("id"),a=e.getAttribute("class"),i=e.tagName.toLowerCase(),o=null;
if(n&&!G(a,"articlepart-selector-area_choice-button_wrap"))return t?"#"+n+">"+t:"#"+n;
var d=D(a);
return o=d?d:G(a,"js_choice-img")?".js_choice-img":G(a,"articlepart-selector-area_choice")&&e.dataset.splitid?"":i,
tt(e.parentNode,[o,t].filter(function(e){
return!!e;
}).join(">"),r);
},Q=function(e,t){
for(var r=L(e,"",t),n=t.querySelectorAll(r),a=n.length,i=null,o=0;a>o;o++)if(e===n[o]){
i=o;
break;
}
null===i&&"undefined"!=typeof WX_BJ_REPORT&&WX_BJ_REPORT.BadJs&&WX_BJ_REPORT.BadJs.report("ArticleMask:Error","selector:node not find",{
mid:"mmbizwap:articlemask_Monitor",
view:"wap_business",
_info:{
selector:r
}
});
var d=(r||"").replace(">.js_choice-img>",">")+("|"+a+" "+(i||0));
return d;
},U=function(e){
return e.map(function(e){
var t=e.$node,r=e.type,n=e.idx,a=0,i=null,o="",d=j(t);
if(r===x.text){
var s=V(d,t.parentNode);
t&&t.data&&(a=s,i=t.data,o=t.previousSibling&&t.previousSibling.data);
}else if(r===x.img){
var u=d.getElementsByTagName("img");
i=t.src,a=Array.prototype.slice.call(u).slice(0).indexOf(t);
}
return{
data:i,
index:a,
idx:n,
type:r,
meta:o
};
}).filter(function(e){
return e.index>-1&&!!e.data;
});
},Y=function(e,t){
var r=t||document.getElementById("js_content");
return e.map(function(e){
var t=e.$node,n=e.type,a=e.idx,i=null,o=null,d="";
return n===x.text?t&&t.data&&(i=Q(t.parentNode,r),o=t.data,d=t.previousSibling&&t.previousSibling.data):n===x.img&&(i=Q(t,r),
o=t.src),{
data:o,
idx:a,
type:n,
meta:d,
selector:i
};
}).filter(function(e){
return!!e.selector&&!!e.data;
});
},F=function(e,t){
return(t||document).querySelector(e);
},K=function(e,t){
return(t||document).querySelectorAll(e);
};
r.exports={
getDomMeta:C,
getContent:u,
getParaList:O,
getBlockNode:j,
getSelectedNodes:B,
connectSiblingText:S,
getTextNodeByOffset:I,
getBlockOffset:a,
getSelection:A,
transferTextToElement:M,
serialize:J,
deSerialize:X,
resetRange:z,
serializeToC:U,
setProperty:d,
hasImgNode:s,
nodeToSelection:i,
saveNode:p,
serializeNode:l,
getNodeByIndex:H,
findChildIndex:c,
serializeToC2:Y,
blockEleTagName:v,
getPureBlockNode:P,
qs:F,
qsAll:K,
hasClass:G
};
});define("appmsg/subscribe/subscribe_btn_tpl.html.js",[],function(){
return'<#if(supportWxOpen){#>\n<wx-open-subscribe template="<#=templateIdList#>" scene="<#=scene#>" username="<#=username#>" scale="<#=scale#>" appmsgindex="<#=appmsgIndex#>"> \n  <template slot="style">\n    <style>\n    .reset_btn{\n      -webkit-appearance: none;\n      -webkit-tap-highlight-color:rgba(0,0,0,0);\n      outline: 0;\n      background-color: transparent;\n      border: 0;\n      font-family:inherit;\n      display: inline-block;\n      vertical-align: middle;\n    }\n    .subsc_btn {\n      font-size:inherit;\n      display: -ms-flexbox;\n      display: flex;\n      -ms-flex-align: center;\n      align-items: center;\n      padding: 0;\n      margin: 0;\n      color: #576b95;\n    }\n    .icon_subsc {\n      display: -ms-flexbox;\n      display: flex;\n      width: 20px;\n      height: 20px;\n      -ms-flex-align: center;\n      align-items: center;\n      -ms-flex-pack: center;\n      justify-content: center;\n      margin-right: 4px;\n      box-sizing: border-box;\n      border-radius: 100%;\n      box-shadow: 0 0 3px 0 rgba(0, 0, 0, 0.1);\n    }\n    .icon_subsc:before {\n      content: "";\n      display: inline-block;\n      vertical-align: middle;\n      width: 14px;\n      height: 14px;\n      -webkit-mask: url("data:image/svg+xml;charset=utf8,%3Csvg xmlns=\'http://www.w3.org/2000/svg\' width=\'14\' height=\'14\' viewBox=\'0 0 14 14\'%3E  %3Cpath fill=\'%23576B95\' d=\'M7 1.167a1.167 1.167 0 0 1 1.15 1.36 3.501 3.501 0 0 1 2.35 3.306v2.334c0 .857.315 1.714.945 2.571a.583.583 0 0 1-.47.929H7.582v.116a.583.583 0 0 1-1.166 0v-.116H3.025a.583.583 0 0 1-.47-.929c.63-.857.944-1.714.944-2.571V5.833c0-1.53.982-2.83 2.35-3.306A1.167 1.167 0 0 1 7 1.167zm0 1a.167.167 0 0 0-.167.166l.003.03.139.831-.797.277a2.501 2.501 0 0 0-1.672 2.185l-.006.177v2.334c0 .833-.23 1.653-.678 2.45l-.029.049h6.413l-.028-.048c-.403-.719-.63-1.454-.671-2.202l-.007-.25V5.834a2.5 2.5 0 0 0-1.515-2.298l-.163-.064-.797-.277.14-.832A.167.167 0 0 0 7 2.166z\'/%3E%3C/svg%3E") no-repeat 50% 50%;\n      mask: url("data:image/svg+xml;charset=utf8,%3Csvg xmlns=\'http://www.w3.org/2000/svg\' width=\'14\' height=\'14\' viewBox=\'0 0 14 14\'%3E  %3Cpath fill=\'%23576B95\' d=\'M7 1.167a1.167 1.167 0 0 1 1.15 1.36 3.501 3.501 0 0 1 2.35 3.306v2.334c0 .857.315 1.714.945 2.571a.583.583 0 0 1-.47.929H7.582v.116a.583.583 0 0 1-1.166 0v-.116H3.025a.583.583 0 0 1-.47-.929c.63-.857.944-1.714.944-2.571V5.833c0-1.53.982-2.83 2.35-3.306A1.167 1.167 0 0 1 7 1.167zm0 1a.167.167 0 0 0-.167.166l.003.03.139.831-.797.277a2.501 2.501 0 0 0-1.672 2.185l-.006.177v2.334c0 .833-.23 1.653-.678 2.45l-.029.049h6.413l-.028-.048c-.403-.719-.63-1.454-.671-2.202l-.007-.25V5.834a2.5 2.5 0 0 0-1.515-2.298l-.163-.064-.797-.277.14-.832A.167.167 0 0 0 7 2.166z\'/%3E%3C/svg%3E") no-repeat 50% 50%;\n      -webkit-mask-size: cover;\n      mask-size: cover;\n      background-color: currentColor;\n    }\n    @media (prefers-color-scheme: dark) {\n      .subsc_btn {\n        color: #7d90a9;\n      }\n      .icon_subsc {\n        box-shadow: 0 0 3px 0 rgba(255, 255, 255, 0.1);\n      }\n    }\n    </style>\n  </template>\n  <template>\n    <div class="subsc_context">\n      <button class="subsc_btn reset_btn" type="button"><i class="icon_subsc"></i>订阅通知</button>\n    </div>\n  </template>\n</wx-open-subscribe>\n<#}else{#>\n  <div class="subsc_context js_subsc_btn">\n    <button class="subsc_btn reset_btn" type="button"><i class="icon_subsc"></i>订阅通知</button>\n  </div>\n<#}#>\n\n\n';
});define("album/utils/report.js",["common/comm_report.js"],function(e){
"use strict";
var i=e("common/comm_report.js"),o=window.WX_BJ_REPORT||{},r=function(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0],r={
BizUin:window.biz,
MsgId:1*window.mid,
ItemIdx:1*window.idx,
ItemShowType:1*window.item_show_type||0,
SessionId:window.sessionid+"",
EnterId:1*window.enterid,
Scene:1*window.source,
SubScene:1*window.subscene,
AlbumId:e.albumId+"",
AlbumType:1*e.albumType,
EventType:1*e.eventType,
Vid:e.vid,
Audioid:e.audioid||"",
Title:e.title||""
};
i.report(19647,r,{
success:function(e){
1*e.err_code!==0&&"undefined"!=typeof o&&o.BadJs&&o.BadJs.report("mmdata report failed","log_id: 19647",{
mid:"mmbizwap:album_Monitor",
_info:{
postData:r,
errCode:e.err_code,
errMsg:e.err_msg
}
});
}
});
},n=function(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0],r={
BizUin:window.biz,
Scene:1*window.source,
SubScene:1*window.subscene,
EnterId:1*window.enterid,
SceneNote:e.sceneNote+"",
AlbumId:e.albumId+"",
AlbumType:1*e.albumType,
EventType:1*e.eventType,
IfSubscription:1*e.isSubscribed===1?2:1,
NewTagId:e.tagId+"",
ShowTag:e.showTag+"",
InsideTag:e.insideTag+"",
Cate1:e.c1+"",
Cate2:e.c2+"",
StayTime:e.stayTime?1*e.stayTime:0,
NetworkType:1*e.networkType
};
i.report(19648,r,{
async:e.async||!0,
success:function(e){
1*e.err_code!==0&&"undefined"!=typeof o&&o.BadJs&&o.BadJs.report("mmdata report failed","log_id: 19648",{
mid:"mmbizwap:album_Monitor",
_info:{
postData:r,
errCode:e.err_code,
errMsg:e.err_msg
}
});
}
});
},d=function(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0],r={
BizUin:window.biz,
MsgId:1*e.msgid,
ItemIdx:1*e.itemidx,
Pos:1*e.pos,
Scene:178,
SubScene:1*window.subscene,
EnterId:1*window.enterid,
SceneNote:e.sceneNote+"",
AlbumId:e.albumId+"",
AlbumType:1*e.albumType,
EventType:1*e.eventType,
Vid:e.vid,
IfSubscription:1*e.isSubscribed===1?2:1,
NewTagId:e.tagId+"",
ShowTag:e.showTag+"",
InsideTag:e.insideTag+"",
Cate1:e.c1+"",
Cate2:e.c2+"",
ArticleSource:1
};
i.report(19649,r,{
success:function(e){
1*e.err_code!==0&&"undefined"!=typeof o&&o.BadJs&&o.BadJs.report("mmdata report failed","log_id: 19649",{
mid:"mmbizwap:album_Monitor",
_info:{
postData:r,
errCode:e.err_code,
errMsg:e.err_msg
}
});
}
}),1*e.eventType===1&&!function(){
var r={
BizUin:window.biz,
MsgId:1*e.msgid,
ItemIdx:1*e.itemidx,
AppMsgUrl:e.url,
Title:e.title,
IsReaded:1*e.isRead,
Scene:1*window.source,
SubScene:1*window.subscene
};
i.report(20805,r,{
success:function(e){
1*e.err_code!==0&&"undefined"!=typeof o&&o.BadJs&&o.BadJs.report("mmdata report failed","log_id: 20805",{
mid:"mmbizwap:album_Monitor",
_info:{
postData:r,
errCode:e.err_code,
errMsg:e.err_msg
}
});
}
});
}();
},t=function(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0],r={
bizuin:window.biz,
url:e.url+"",
ActionType:1*e.actionType,
Scene:1*window.source,
Network:window.__networkType+"",
AlbumId:e.albumId+"",
AlbumType:1*e.albumType,
ExpType:window.exptype||"",
ExpSessionIdStr:window.expsessionid||""
};
i.report(10380,r,{
success:function(e){
1*e.err_code!==0&&"undefined"!=typeof o&&o.BadJs&&o.BadJs.report("mmdata report failed","log_id: 10380",{
mid:"mmbizwap:album_Monitor",
_info:{
postData:r,
errCode:e.err_code,
errMsg:e.err_msg
}
});
}
});
},s=function(){
var e=arguments.length<=0||void 0===arguments[0]?{}:arguments[0],r={
BizUin:window.biz,
Action:1*e.action,
AppMsgLikeType:window.appmsg_like_type,
Scene:1*window.source,
SubScene:1*window.subscene,
AlbumId:e.albumId+"",
AlbumType:1*e.albumType,
ExpType:window.exptype||"",
ExpSessionIdStr:window.expsessionid||""
};
i.report(14299,r,{
success:function(e){
1*e.err_code!==0&&"undefined"!=typeof o&&o.BadJs&&o.BadJs.report("mmdata report failed","log_id: 14299",{
mid:"mmbizwap:album_Monitor",
_info:{
postData:r,
errCode:e.err_code,
errMsg:e.err_msg
}
});
}
});
};
return{
cardReport:r,
albumActionReport:n,
articleActionReport:d,
shareReport:t,
likeReport:s
};
});define("common/color/light.js",[],function(){
"use strict";
return{
"BG-0":"#ededed",
"BG-1":"#f7f7f7",
"BG-2":"#ffffff",
"BG-3":"#f7f7f7",
"BG-4":"#4c4c4c",
"BG-5":"#ffffff",
"FG-0":"rgba(0, 0, 0, 0.9)",
"FG-HALF":"rgba(0, 0, 0, 0.9)",
"FG-1":"rgba(0, 0, 0, 0.5)",
"FG-2":"rgba(0, 0, 0, 0.3)",
"FG-3":"rgba(0, 0, 0, 0.1)",
RED:"#fa5151",
ORANGE:"#fa9d3b",
YELLOW:"#ffc300",
GREEN:"#91d300",
LIGHTGREEN:"#95ec69",
BRAND:"#07c160",
BLUE:"#10aeff",
INDIGO:"#1485ee",
PURPLE:"#6467f0",
WHITE:"#fff",
LINK:"#576b95",
TEXTGREEN:"#06ae56",
FG:"black",
BG:"white",
"TAG-TEXT-ORANGE":"#fa9d3b",
"TAG-BACKGROUND-ORANGE":"rgba(250, 157, 59, 0.1)",
"TAG-TEXT-GREEN":"#06ae56",
"TAG-BACKGROUND-GREEN":"rgba(6, 174, 86, 0.1)",
"TAG-TEXT-BLUE":"#10aeff",
"TAG-BACKGROUND-BLUE":"rgba(16, 174, 255, 0.1)",
"TAG-TEXT-BLACK":"rgba(0, 0, 0, 0.5)",
"TAG-BACKGROUND-BLACK":"rgba(0, 0, 0, 0.05)"
};
});