�
 TFORM1 0�   TPF0TForm1Form1Left� TopZWidthNHeight�Caption   Aggregate 功能範例程式Color	clBtnFaceFont.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.Style OldCreateOrderPositionpoScreenCenterOnCreate
FormCreatePixelsPerInch`
TextHeight TLabelLabel1Left� Top�Width2HeightCaption
OrderTotal  TLabelLabel2LeftSTop�WidthnHeightCaptionOrderTotal Per ShipVIA  TPanelPanel2Left Top� WidthFHeight7AlignalClientCaptionPanel2TabOrder  TLabelLabel12LeftTop� WidthpHeightCaption   ��K�lQ�ST1z�Font.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.Style 
ParentFont  TLabelLabel13LeftTop� Width� HeightCaption	   ��K�lQ�SK��=~M��Font.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.Style 
ParentFont  TLabelLabel14LeftTopWidth� HeightCaption	   �kP�[6b��U=~M��Font.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.Style 
ParentFont   TPanelPanel1Left Top WidthFHeight� AlignalTopFont.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.Style 
ParentFontTabOrder TLabelLabel3LeftTop-WidthQHeightAutoSizeCaption   �[6b�}_��FocusControlDBEdit1  TLabelLabel4LeftTopGWidthQHeightAutoSizeCaption   lQ�ST1z�FocusControlDBEdit4  TLabelLabel5LeftTopbWidthQHeightAutoSizeCaption   ���0W@W�FocusControlDBEdit5  TLabelLabel6LeftTop|WidthQHeightAutoSizeCaption   lQ�S0W@W�FocusControlDBEdit6  TLabelLabel7Left!Top+WidthPHeightAutoSizeCaption   @b(W�W^�FocusControlDBEdit7  TLabelLabel9Left!TopFWidthPHeightAutoSizeCaption   @b(WW�[�FocusControlDBEdit9  TLabelLabel10Left!Top`WidthPHeightAutoSizeCaption   o�a}��q��FocusControlDBEdit10  TLabelLabel11Left!TopzWidthPHeightAutoSizeCaption   �Pw��q��FocusControlDBEdit11  TDBEditDBEdit1Left]Top)Width<Height	DataFieldCustNo
DataSourceCustOrdersDataSourceTabOrder   TDBEditDBEdit4Left\TopCWidth� Height	DataFieldCompany
DataSourceCustOrdersDataSourceTabOrder  TDBEditDBEdit5Left\Top^Width� Height	DataFieldAddr1
DataSourceCustOrdersDataSourceTabOrder  TDBEditDBEdit6Left\TopxWidth� Height	DataFieldAddr2
DataSourceCustOrdersDataSourceTabOrder  TDBEditDBEdit7LeftoTop'WidthYHeight	DataFieldCity
DataSourceCustOrdersDataSourceTabOrder  TDBEditDBEdit9LeftoTopAWidthuHeight	DataFieldCountry
DataSourceCustOrdersDataSourceTabOrder  TDBEditDBEdit10LeftoTop[WidthYHeight	DataFieldPhone
DataSourceCustOrdersDataSourceTabOrder  TDBEditDBEdit11LeftoTopuWidthYHeight	DataFieldFAX
DataSourceCustOrdersDataSourceTabOrder   TDBGridDBGrid1LeftTop� Width&Height� 
DataSourceOrderDSDataSourceFont.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.Style 
ParentFontTabOrderTitleFont.CharsetDEFAULT_CHARSETTitleFont.ColorclWindowTextTitleFont.Height�TitleFont.NameMS Sans SerifTitleFont.Style   TDBNavigatorDBNavigator1LeftTopWidth� Height
DataSourceCustOrdersDataSourceTabOrder  TDBEditDBEdit2Left�Top�WidthyHeight	DataFieldTotalPerCustomer
DataSourceOrderDSDataSourceTabOrder  TDBNavigatorDBNavigator2LeftTop� Width� Height
DataSourceOrderDSDataSourceTabOrder  TDBEditDBEdit3Left�Top�WidthyHeight	DataFieldOrderTotalPerShipMethod
DataSourceOrderDSDataSourceTabOrder  TDBEditDBTextShipMethodLeft~Top�WidthXHeight	DataFieldShipVIA
DataSourceOrderDSDataSourceTabOrder  TDataSourceCustDataSourceDataSet	CustQueryLeft� TopH  TQuery	CustQueryDatabaseNameBCDEMOSSQL.Stringsselect * from customerwhere CustNo < 1500 Left� TopH TFloatFieldCustQueryCustNo	FieldNameCustNoOrigin"customer.DB".CustNo  TStringFieldCustQueryCompany	FieldNameCompanyOrigin"customer.DB".CompanySize  TStringFieldCustQueryAddr1	FieldNameAddr1Origin"customer.DB".Addr1Size  TStringFieldCustQueryAddr2	FieldNameAddr2Origin"customer.DB".Addr2Size  TStringFieldCustQueryCity	FieldNameCityOrigin"customer.DB".CitySize  TStringFieldCustQueryState	FieldNameStateOrigin"customer.DB".State  TStringFieldCustQueryZip	FieldNameZipOrigin"customer.DB".ZipSize
  TStringFieldCustQueryCountry	FieldNameCountryOrigin"customer.DB".Country  TStringFieldCustQueryPhone	FieldNamePhoneOrigin"customer.DB".PhoneSize  TStringFieldCustQueryFAX	FieldNameFAXOrigin"customer.DB".FAXSize  TFloatFieldCustQueryTaxRate	FieldNameTaxRateOrigin"customer.DB".TaxRate  TStringFieldCustQueryContact	FieldNameContactOrigin"customer.DB".Contact  TDateTimeFieldCustQueryLastInvoiceDate	FieldNameLastInvoiceDateOrigin"customer.DB".LastInvoiceDate   TQuery
OrderQueryDatabaseNameBCDEMOS
DataSourceCustDataSourceSQL.Stringsselect * from orderswhere CustNo = :CustNo Left� TopH	ParamDataDataTypeftFloatNameCustNo	ParamType	ptUnknown    TClientDataSet
CustOrders
Aggregates Params ProviderNameDataSetProvider1LeftTopH TFloatFieldCustOrdersCustNo	FieldNameCustNo  TStringFieldCustOrdersCompany	FieldNameCompanySize  TStringFieldCustOrdersAddr1	FieldNameAddr1Size  TStringFieldCustOrdersAddr2	FieldNameAddr2Size  TStringFieldCustOrdersCity	FieldNameCitySize  TStringFieldCustOrdersState	FieldNameState  TStringFieldCustOrdersZip	FieldNameZipSize
  TStringFieldCustOrdersCountry	FieldNameCountry  TStringFieldCustOrdersPhone	FieldNamePhoneSize  TStringFieldCustOrdersFAX	FieldNameFAXSize  TFloatFieldCustOrdersTaxRate	FieldNameTaxRate  TStringFieldCustOrdersContact	FieldNameContact  TDateTimeFieldCustOrdersLastInvoiceDate	FieldNameLastInvoiceDate  TDataSetFieldCustOrdersOrderQuery	FieldName
OrderQuery   TDataSourceCustOrdersDataSourceDataSet
CustOrdersLeftHTopH  TDataSourceOrderDSDataSourceDataSetOrderDSLefthTopH  TClientDataSetOrderDS
Aggregates AggregatesActive	DataSetFieldCustOrdersOrderQuery	FieldDefsNameOrderNoDataTypeftFloat NameCustNoDataTypeftFloat NameSaleDateDataType
ftDateTime NameShipDateDataType
ftDateTime NameEmpNoDataType	ftInteger NameShipToContactDataTypeftStringSize NameShipToAddr1DataTypeftStringSize NameShipToAddr2DataTypeftStringSize Name
ShipToCityDataTypeftStringSize NameShipToStateDataTypeftStringSize Name	ShipToZipDataTypeftStringSize
 NameShipToCountryDataTypeftStringSize NameShipToPhoneDataTypeftStringSize NameShipVIADataTypeftStringSize NamePODataTypeftStringSize NameTermsDataTypeftStringSize NamePaymentMethodDataTypeftStringSize Name
ItemsTotalDataType
ftCurrency NameTaxRateDataTypeftFloat NameFreightDataType
ftCurrency Name
AmountPaidDataType
ftCurrency  	IndexDefsNameShipVIAFieldsShipVIA  	IndexNameShipVIAParams 	StoreDefs	Left(TopH TFloatFieldOrderDSOrderNoDisplayLabel   ��U�}_�	FieldNameOrderNo  TStringFieldOrderDSShipVIADisplayLabel   ��K�lQ�S	FieldNameShipVIASize  TCurrencyFieldOrderDSItemsTotalDisplayLabel   ��UёM�	FieldName
ItemsTotal  TDateTimeFieldOrderDSSaleDateDisplayLabel   ��U�eg	FieldNameSaleDate  TDateTimeFieldOrderDSShipDateDisplayLabel   �Q���eg	FieldNameShipDate  TStringFieldOrderDSPaymentMethodDisplayLabel   �N>k�e_	FieldNamePaymentMethodSize  TFloatFieldOrderDSTaxRateDisplayLabel   z�s	FieldNameTaxRate  TAggregateFieldOrderDSTotalPerCustomer	FieldNameTotalPerCustomerActive	
Expressionsum( ItemsTotal )  TAggregateFieldOrderDSOrderTotalPerShipMethod	FieldNameOrderTotalPerShipMethodActive	
Expressionsum( ItemsTotal )GroupingLevel	IndexNameShipVIA   TDataSetProviderDataSetProvider1DataSet
CustOrdersConstraints	Left� TopH   