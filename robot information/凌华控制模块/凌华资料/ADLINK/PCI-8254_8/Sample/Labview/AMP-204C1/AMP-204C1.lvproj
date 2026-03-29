<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="12008004">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="AMP-204C1.vi" Type="VI" URL="../AMP-204C1.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="APS168x64.dll" Type="Document" URL="APS168x64.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
			<Item Name="APS168x64.lvlib" Type="Library" URL="../APS168x64.lvlib"/>
		</Item>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="AMP-204C1" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{5C79C181-5C10-4DD4-8981-0A5932CF4B2D}</Property>
				<Property Name="App_INI_GUID" Type="Str">{76C5E581-1F74-46DF-90CA-D190662CBB82}</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{35EA0BED-0FAE-446D-8B52-DDE3F26D7918}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">AMP-204C1</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/NI_AB_PROJECTNAME</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{4C1CC868-465F-412F-BF91-CD87E2810037}</Property>
				<Property Name="Destination[0].destName" Type="Str">AMP-204C1.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/NI_AB_PROJECTNAME/AMP-204C1.exe</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/NI_AB_PROJECTNAME/data</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{CA353085-9E2C-49C9-8EE9-68FAE5477B53}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/AMP-204C1.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">ADLINK</Property>
				<Property Name="TgtF_fileDescription" Type="Str">AMP-204C1</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">AMP-204C1</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright ?2015 ADLINK</Property>
				<Property Name="TgtF_productName" Type="Str">AMP-204C1</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{7A654403-78C5-4F8A-AF5A-679D8C3CDD79}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">AMP-204C1.exe</Property>
			</Item>
		</Item>
	</Item>
</Project>
