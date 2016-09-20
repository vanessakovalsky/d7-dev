<?php
function demo_entity_views_data(){
    $data['demo']['table']['group'] = t('Demo');
    $data['demo']['table']['base'] = array(
        'field' => 'did',
        'title' => t('Demo'),
        'help' => t('Entité démo'),
    );

    $data['demo']['did'] = array(
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