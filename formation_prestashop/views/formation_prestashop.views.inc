<?php

function formation_prestashop_views_data(){
  $data['babyfoot']['table']['group'] = t('Babyfoot');
   $data['babyfoot']['table']['base'] = array(
       'field' => 'bid',
       'title' => t('Babyfoot'),
       'help' => t('Entité babyfoot'),
   );
   $data['babyfoot']['bid'] = array(
       'title' => t('Id de la demo'),
       'field' => array(
           'handler' => 'views_handler_field_numeric',
           'click sortable' => TRUE,
       ),
       'filter' => array(
           'handler' => 'views_handler_filter_numeric',
       ),
       'sort' => array(
           'handler' => 'field_handler_sort',
       ),
       'argument' => array(
           'handler' => 'field_handler_argument_numeric',
       ),
   );
   return $data;
}
