�
 TFORM1 06  TPF0TForm1Form1Left� TopxWidth�Height,Caption   FUN�QV{R�g�~�Nz�^��OColor	clBtnFaceFont.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.Style Menu	MainMenu1OldCreateOrder	PixelsPerInch`
TextHeight TDecisionPivotDecisionPivot1Left Top Width�Height9ButtonAutoSize	DecisionSourceDecisionSource1GroupLayoutxtHorizontalGroupsxtRows	xtColumnsxtSummaries ButtonSpacingButtonWidth@ButtonHeightGroupSpacing
BorderWidthBorderStylebsNoneAlignalTopFont.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameTimes New Roman
Font.Style 
ParentFontTabOrder   TDecisionGridDecisionGrid1Left Top9Width�Height�DefaultColWidthLDefaultRowHeightCaptionColorclActiveCaptionCaptionFont.CharsetDEFAULT_CHARSETCaptionFont.ColorclCaptionTextCaptionFont.Height�CaptionFont.NameTimes New RomanCaptionFont.Style 	DataColorclInfoBkDataSumColorclRedDataFont.CharsetDEFAULT_CHARSETDataFont.ColorclWindowTextDataFont.Height�DataFont.NameTimes New RomanDataFont.Style LabelFont.CharsetDEFAULT_CHARSETLabelFont.ColorclWindowTextLabelFont.Height�LabelFont.NameTimes New RomanLabelFont.Style 
LabelColor	clBtnFaceLabelSumColorclInactiveCaptionDecisionSourceDecisionSource1
Dimensions	FieldName   '�ЏlQ�SColorclNone	AlignmenttaCenter	Subtotals	 	FieldName   �N>k�e_ColorclNone	AlignmenttaCenter	Subtotals	 	FieldName   �N'��e_ColorclNone	AlignmenttaCenter	Subtotals	 	FieldName   �Q'��egColorclNone	AlignmenttaCenter	Subtotals	 	FieldName   '�Џ9�(uColorclNone	AlignmenttaCenter	Subtotals	 	FieldName   �Q'�!kpeColorclNone	AlignmenttaCenter	Subtotals	 	FieldName   '�Џ9�(us^GW<PColorclNone	AlignmenttaCenter	Subtotals	  Totals	ShowCubeEditorAlignalClientColor	clBtnFaceGridLineWidthGridLineColorclWindowTextTabOrder  TDecisionCubeDecisionCube1DataSetDecisionQuery1DimensionMap
ActiveFlag
diAsNeeded	FieldTypeftString	FieldnameShipVIABaseName"ORDERS.DB".ShipVIAName   '�ЏlQ�SDerivedFrom�DimensionTypedimDimensionBinTypebinNone
ValueCountActive	 
ActiveFlag
diAsNeeded	FieldTypeftString	FieldnamePaymentMethodBaseName"ORDERS.DB".PaymentMethodName   �N>k�e_DerivedFrom�DimensionTypedimDimensionBinTypebinNone
ValueCountActive	 
ActiveFlag
diAsNeeded	FieldTypeftString	FieldnameTermsBaseName"ORDERS.DB".TermsName   �N'��e_DerivedFrom�DimensionTypedimDimensionBinTypebinNone
ValueCountActive	 
ActiveFlag
diAsNeeded	FieldType
ftDateTime	FieldnameShipDateBaseName"ORDERS.DB".ShipDateName   �Q'��egDerivedFrom�DimensionTypedimDimensionBinTypebinMonth
ValueCount2Active	
StartValue      g�@ 
ActiveFlagdiActive	FieldType
ftCurrency	FieldnameSUM OF AmountPaidBaseName"ORDERS.DB".AmountPaidName   '�Џ9�(uDerivedFrom�DimensionTypedimSumBinTypebinNone
ValueCount�Active	 
ActiveFlag
diAsNeeded	FieldType	ftInteger	FieldnameCOUNT OF AmountPaidBaseName"ORDERS.DB".AmountPaidName   �Q'�!kpeDerivedFrom�DimensionTypedimCountBinTypebinNone
ValueCount�Active	 
ActiveFlag
diAsNeeded	FieldType	ftUnknown	Fieldname"   平均值："ORDERS.DB".AmountPaidBaseName"ORDERS.DB".AmountPaidName   '�Џ9�(us^GW<PDerivedFromDimensionType
dimAverageBinTypebinNone
ValueCount�Active	  ShowProgressDialog	MaxDimensionsMaxSummaries
MaxCells Left Top�  TDecisionQueryDecisionQuery1Active	DatabaseNameBCDEMOSSQL.StringsVSELECT ShipVIA, PaymentMethod, Terms, ShipDate, SUM( AmountPaid ), COUNT( AmountPaid )FROM "ORDERS.DB"0GROUP BY ShipVIA, PaymentMethod, Terms, ShipDate LeftPTop�  TDecisionSourceDecisionSource1DecisionCubeDecisionCube1ControlTypextCheck
SparseRows
SparseColsLeft� Top�DimensionCountSummaryCountCurrentSummary 
SparseRows
SparseColsDimensionInfo�      �   	TMainMenu	MainMenu1LeftTop� 	TMenuItemN1Caption	   >f:y�[�^�v�~���Vh�OnClickN1Click    