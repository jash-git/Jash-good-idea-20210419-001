?
 TDM 0   TPF0TDMDMOldCreateOrder	LeftTop? Height? Width?  TTableCustomerActive		AfterPostCustomerAfterPostOnDeleteErrorCustomerDeleteErrorOnPostErrorCustomerPostErrorDatabaseNameBCDEMOS	FieldDefsNameCustNoDataTypeftFloat NameCompanyDataTypeftStringSize NameAddr1DataTypeftStringSize NameAddr2DataTypeftStringSize NameCityDataTypeftStringSize NameStateDataTypeftStringSize NameZipDataTypeftStringSize
 NameCountryDataTypeftStringSize NamePhoneDataTypeftStringSize NameFAXDataTypeftStringSize NameTaxRateDataTypeftFloat NameContactDataTypeftStringSize NameLastInvoiceDateDataType
ftDateTime  	StoreDefs		TableNameCUSTOMER.DBLeftTop TFloatFieldCustomerCustNo	AlignmenttaLeftJustifyDisplayWidth	FieldNameCustNoOnChangeCustomerCustNoChangeDisplayFormatCN 0000
EditFormat0000MaxValue      <?@MinValue       ?@  TStringFieldCustomerCompanyDisplayWidth	FieldNameCompanySize   TDataSourceCustomerSourceDataSetCustomerLeftQTop  TTableOrdersActive	OnDeleteErrorOrdersDeleteErrorOnPostErrorOrdersPostErrorDatabaseNameBCDEMOS	FieldDefsNameOrderNoDataTypeftFloat NameCustNo
Attributes
faRequired DataTypeftFloat NameSaleDateDataType
ftDateTime NameShipDateDataType
ftDateTime NameEmpNo
Attributes
faRequired DataType	ftInteger NameShipToContactDataTypeftStringSize NameShipToAddr1DataTypeftStringSize NameShipToAddr2DataTypeftStringSize Name
ShipToCityDataTypeftStringSize NameShipToStateDataTypeftStringSize Name	ShipToZipDataTypeftStringSize
 NameShipToCountryDataTypeftStringSize NameShipToPhoneDataTypeftStringSize NameShipVIADataTypeftStringSize NamePODataTypeftStringSize NameTermsDataTypeftStringSize NamePaymentMethodDataTypeftStringSize Name
ItemsTotalDataType
ftCurrency NameTaxRateDataTypeftFloat NameFreightDataType
ftCurrency Name
AmountPaidDataType
ftCurrency  	IndexDefsFieldsOrderNoOptions	ixPrimaryixUnique  NameCustNoFieldsCustNo  	IndexNameCustNoMasterFieldsCustNoMasterSourceCustomerSource	StoreDefs		TableName	ORDERS.DBLeftTopF TFloatFieldOrdersOrderNoDisplayWidth
	FieldNameOrderNoDisplayFormat'#'0000
EditFormat0000  TFloatFieldOrdersCustNo	AlignmenttaLeftJustify	FieldNameCustNoDisplayFormatCN 0000
EditFormat0000MaxValue      <?@MinValue       ?@  TDateTimeFieldOrdersSaleDate	FieldNameSaleDate  TDateTimeFieldOrdersShipDate	FieldNameShipDate  TIntegerFieldOrdersEmpNo	FieldNameEmpNoDisplayFormatEmp'#' 0000
EditFormat0000MaxValue'MinValue   TDataSourceOrdersSourceDataSetOrdersLeftQTopF  TTableItemsActive	OnPostErrorItemsPostErrorDatabaseNameBCDEMOS	FieldDefsNameOrderNoDataTypeftFloat NameItemNoDataTypeftFloat NamePartNoDataTypeftFloat NameQtyDataType	ftInteger NameDiscountDataTypeftFloat  	IndexDefsFieldsOrderNo;ItemNoOptions	ixPrimaryixUnique  Name	ByOrderNoFieldsOrderNoOptionsixCaseInsensitive  NamePartNoFieldsPartNo  IndexFieldNamesOrderNoMasterFieldsOrderNoMasterSourceOrdersSource	StoreDefs		TableNameITEMS.DBLeftTop?  TFloatFieldItemsOrderNoDisplayWidth
	FieldNameOrderNoDisplayFormat0000  TFloatFieldItemsItemNoDisplayWidth
	FieldNameItemNo  TFloatFieldItemsPartNo	AlignmenttaLeftJustifyDisplayWidth
	FieldNamePartNoDisplayFormatPN-00000
EditFormat00000  TIntegerFieldItemsQtyDisplayWidth	FieldNameQty  TFloatFieldItemsDiscountDisplayWidth
	FieldNameDiscountDisplayFormat#%MinValue       ?@   TDataSourceItemsSourceDataSetItemsLeftQTop?    