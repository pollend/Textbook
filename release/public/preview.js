//Copyright Michael Pollind 2014

//gallery group -> 0 = image 1 = caption
var gallerygroup = new Array();
var isImageOverlayActive = false;

var selectedGallery = 0;
var selectedImage = 0;

var lockImageProgression = false;



$(window ).load(function(){
	UpdateImageViews();
});



function UpdateImageViews()
{
	gallerygroup = new Array();

	$("a[href$='.jpg'],a[href$='.png']").each(function(){

		var gallery = new Array();
		var item = new Array();
		item.push($(this).attr("href")); //push href onto item
		item.push($(this).parent().find(".wp-caption-text").html());//push caption
		gallery.push(item);

		$(this).unbind('click').on("click",{galleryID :(gallerygroup.length) , imageID : (gallery.length-1)},function(event){
			ImageOverlay(event.data.galleryID,event.data.imageID);
			return false;
		});

		gallerygroup.push(gallery);
	});

	//looks for each gallery grouping
	$(".gallery").each(function(){

		

			var gallery = new Array();
			var numberOfItems = $(this).find("a[href$='.jpg'],a[href$='.png']").length;
			var index = 0;
			$(this).find("a[href$='.jpg'],a[href$='.png']").each(function(){
				//var gallery = new Array();
				var item = new Array();
				item.push($(this).attr("href")); //push href onto item
				item.push($(this).parent().find(".wp-caption-text").html());//push caption
				gallery.push(item);

				$(this).unbind('click').on("click",{galleryID :(gallerygroup.length) , imageID : (gallery.length-1)},function(event){
					ImageOverlay(event.data.galleryID,event.data.imageID);
					return false;
				});
				index++;
				if(numberOfItems === index)
				{
					gallerygroup.push(gallery);
				}

			});

	});

}

$(document).ready(function () {

	$("#image-overlay-close").on("click",function(){
		ImageOverlayClose();
		return false;
	});

	$("#overlay-backdrop").on("click",function(){
		ImageOverlayClose();
		return false;
	});

	$("#overlay-enlarged-image-container").on("click",function(){
		ImageOverlayClose();
		return false;
	});

	$("#image-overlay-left").on("click",function(event){
		var imageID = selectedImage;
		imageID--;
		if(imageID < 0)
		{
			imageID = gallerygroup[selectedGallery].length -1;
		}
		ImageOverlay(selectedGallery,imageID);
		event.stopImmediatePropagation();
		return false;
	});
	$("#image-overlay-right").on("click",function(event){
		var imageID = selectedImage;
		imageID++;
		if(imageID >= gallerygroup[selectedGallery].length)
		{
			imageID = 0;
		}
		ImageOverlay(selectedGallery,imageID);
		event.stopImmediatePropagation();
		return false;
	});
});

function load_image () {
	
					$("#image-overlay-image").css({width:"auto",height:"auto"});

						var lImageWidth = $("#image-overlay-image").width();
						var lImageHeight = $("#image-overlay-image").height();
						var laspectRatio =lImageWidth/lImageHeight;
						var lScreenWidth = $(window).width();
						var lScreenHeight = $(window).height();

						//make sure image dosent leave screen
						if((lImageHeight+95) > lScreenHeight )
						{
							lImageWidth = Math.round(laspectRatio*(lScreenHeight-150));
							lImageHeight = Math.round(lScreenHeight-150);
						}
						if(lImageWidth > lScreenWidth)
						{
							lImageWidth = Math.round(lScreenWidth-25);
							lImageHeight =Math.round((lScreenWidth-25)/laspectRatio);
						}
						$("#image-overlay-image").width(lImageWidth-10);
						$("#image-overlay-image").height(lImageHeight-10);


						$("#overlay-image").transition({width:lImageWidth},100,function(){
							$("#overlay-image").transition({height:(lImageHeight + $("#image-overlay-caption").height())},100,function(){
								
								$("#image-overlay-caption .image-caption").transition({"opacity":1},100);
								$("#image-overlay-image").transition({"opacity":1},300);	
								$("#image-over-loading").css({display:"none"});
								lockImageProgression = false;
							});
						});
}

function ImageOverlay( gallerID,  itemID){

	if(isImageOverlayActive !== true)
	{
		isImageOverlayActive = true;

		$("#overlay-backdrop").css({"display":"block","opacity":0});
		$("#overlay-enlarged-image-container").css({"display":"block","opacity":0});
		$("#overlay-backdrop").transition({opacity:1},500);
		$("#overlay-enlarged-image-container").transition({opacity:1,top: ($(document).scrollTop()+95)},500);
		$("#image-overlay-caption").css("display","block");
	}
	

	if(lockImageProgression === false)
	{
		lockImageProgression = true;
		selectedGallery = gallerID;
		selectedImage = itemID;

		var lItem = gallerygroup[gallerID][itemID];
			//set undefined to ""
			if(typeof lItem[1] === 'undefined')
			{
				lItem[1] ="";
			}
			//set caption and number of images
			$("#image-overlay-caption .image-caption").html(lItem[1]);
			$("#image-overlay-caption .num-images").html("image "+ (selectedImage +1)+" of " + gallerygroup[selectedGallery].length );
			$("#image-overlay-caption .image-caption").attr("style","")
			$("#image-overlay-caption .image-caption").css({opacity:"0"});

			if(gallerygroup[selectedGallery].length === 1)
			{
				$("#image-overlay-left").css({display:"none"});
				$("#image-overlay-right").css({display:"none"});
			}
			else
			{
				$("#image-overlay-left").css({display:"block"});
				$("#image-overlay-right").css({display:"block"});
			}

			$("#image-over-loading").css({display:"block"});

			$("#image-overlay-image").transition({"opacity":0},300,function(){
				if($("#image-overlay-image").attr("src") !== lItem[0])
				{
					$("#image-overlay-image").one("load",load_image); 
				}
				else
				{
					load_image();
				}
				$("#image-overlay-image").attr("src",lItem[0]); 
		});	
	}
}


function ImageOverlayClose()
{
	if(isImageOverlayActive === true)
	{
		isImageOverlayActive = false;
		$("#overlay-backdrop").transition({opacity:0},500);
		$("#overlay-enlarged-image-container").transition({opacity:0},500,function(){
			$("#overlay-backdrop").css({"display":"none"});
			$("#overlay-enlarged-image-container").css({"display":"none"});
			lockImageProgression = false;
		});

	}

}



